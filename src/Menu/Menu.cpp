#include "Menu/Menu.hpp"

Menu::Menu(void) :
    m_isSelected(false), m_current(0) {

}

void Menu::draw(u8g2_t *u8g2, int y) {
    Menu::drawFrom(u8g2, y, 0);
}

int Menu::getDrawPriority(void) {
    return 1;
}

int Menu::getHeight(void) {
    int height = 0;
    for (size_t i = 0; i < m_subViews.size(); i++) {
        height += m_subViews[i]->getHeight();
    }
    return height;
}

int Menu::wheel(int count) {
    while (count != 0) {
        int startingView = m_current;

        if (m_current < m_subViews.size() && m_subViews[m_current]->isSelectable()) count = m_subViews[m_current]->wheel(count);

        size_t nextSelectableView = getNextSelectableView(m_current);
        size_t prevSelectableView = getPrevSelectableView(m_current);

        if (count > 0 && m_current < nextSelectableView) {
            m_current = nextSelectableView;
            count--;
        } else if (count < 0 && m_current > prevSelectableView) {
            m_current = prevSelectableView;
            count++;
        } else {
            break;
        }

        if (startingView < m_subViews.size() && m_subViews[startingView]->isSelectable()) {
            m_subViews[startingView]->deselect();
        }
        if (m_current < m_subViews.size() && m_subViews[m_current]->isSelectable()) {
            m_subViews[m_current]->select();
        }
    }

    return count;
}

void Menu::button(View::press_t press) {
    if (m_current < m_subViews.size() && m_subViews[m_current]->isSelectable()) {
        m_subViews[m_current]->button(press);
    }
}

bool Menu::isSelectable(void) {
    for (size_t i = 0; i < m_subViews.size(); i++) {
        if (m_subViews[i]->isSelectable()) {
            return true;
        }
    }
    return false;
}

void Menu::select(void) {
    if (!m_isSelected) {
        m_isSelected = true;

        if (m_current < m_subViews.size() && m_subViews[m_current]->isSelectable()) {
            m_subViews[m_current]->select();
            return;
        }

        m_current = getNextSelectableView(m_current);

        if (m_current < m_subViews.size() && m_subViews[m_current]->isSelectable()) {
            m_subViews[m_current]->select();
            return;
        }

        m_current = getPrevSelectableView(m_current);

        if (m_current < m_subViews.size() && m_subViews[m_current]->isSelectable()) {
            m_subViews[m_current]->select();
            return;
        }
    }
}

void Menu::deselect(void) {
    if (m_isSelected) {
        m_isSelected = false;

        if (m_current < m_subViews.size() && m_subViews[m_current]->isSelectable()) {
            m_subViews[m_current]->deselect();
        }
    }
}

void Menu::addSubView(View* view) {
    m_subViews.push_back(view);
}

void Menu::removeSubView(View* view) {
    for (size_t i = 0; i < m_subViews.size(); i++) {
        if (view == m_subViews[i]) {
            for (size_t j = i; j < m_subViews.size() - 1; j++) {
                m_subViews[j] = m_subViews[j + 1];
            }
            m_subViews.pop_back();

            if (m_current == i && m_subViews[m_current]->isSelectable() && m_isSelected) {
                m_subViews[m_current]->deselect();
            }

            m_current = 0;

            for (size_t j = i; j < m_subViews.size(); j++) {
                if (m_subViews[j]->isSelectable()) {
                    m_current = j;
                    break;
                }
            }

            if (m_current == 0 && i > 0) {
                for (size_t j = i - 1; j > 0; j--) {
                    if (m_subViews[j]->isSelectable()) {
                        m_current = j;
                        break;
                    }
                }
            }

            if (m_subViews[m_current]->isSelectable() && m_isSelected) {
                m_subViews[m_current]->select();
            }

            wheel(0);

            return;
        }
    }
}

View* Menu::getCurrentView(void) {
    if (m_subViews[m_current]->isSelectable()) {
        return m_subViews[m_current];
    } else {
        return NULL;
    }
}

void Menu::resetCurrentView(void) {
    if (m_subViews[m_current]->isSelectable() && m_isSelected) {
        m_subViews[m_current]->deselect();
    }

    m_current = 0;
    if (!m_subViews[m_current]->isSelectable()) {
        m_current = getNextSelectableView(0);
    }

    if (m_subViews[m_current]->isSelectable() && m_isSelected) {
        m_subViews[m_current]->select();
    }
}

size_t Menu::getNumSubViews(void) {
    return m_subViews.size();
}

View* Menu::getSubView(size_t index) {
    if (index < m_subViews.size()) {
        return m_subViews[index];
    } else {
        return NULL;
    }
}

size_t Menu::getNextSelectableView(size_t startingIndex) {
    for (size_t i = startingIndex + 1; i < m_subViews.size(); i++) {
        if (m_subViews[i]->isSelectable()) {
            return i;
        }
    }
    return startingIndex;
}

size_t Menu::getPrevSelectableView(size_t startingIndex) {
    for (size_t i = 1; i <= startingIndex; i++) {
        if (m_subViews[startingIndex - i]->isSelectable()) {
            return startingIndex - i;
        }
    }
    return startingIndex;
}

void Menu::drawFrom(u8g2_t *u8g2, int y, size_t start) {
    int priority = 0;
    for (size_t i = start; i < m_subViews.size(); i++) {
        if (priority < m_subViews[i]->getDrawPriority()) {
            priority = m_subViews[i]->getDrawPriority();
        }
    }
    while (priority > 0) {
        int ty = y;
        for (size_t i = start; i < m_subViews.size(); i++) {
            if (priority == m_subViews[i]->getDrawPriority()) {
                m_subViews[i]->draw(u8g2, ty);
            }
            ty += m_subViews[i]->getHeight();
        }
        priority--;
    }
}

void Menu::swap(size_t a, size_t b) {
    View* tmp = m_subViews[a];
    m_subViews[a] = m_subViews[b];
    m_subViews[b] = tmp;
}