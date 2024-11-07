#include "Menu/DragOnScrollableMenu.hpp"

#include "esp_log.h"

#define TAG "DragOnScrollableMenu"

DragOnScrollableMenu::DragOnScrollableMenu(int height) :
    ScrollableMenu(height), m_isDragging(false), m_drag(nullptr) {

}

void DragOnScrollableMenu::draw(u8g2_t *u8g2, int y) {
    ScrollableMenu::draw(u8g2, y);

    if (m_isDragging && m_current < m_subViews.size()) {
        for (size_t i = m_scrollPosition; i < m_current; i++) {
            y += m_subViews[i]->getHeight();
        }
        int h = m_subViews[m_current]->getHeight();

        u8g2_SetDrawColor(u8g2, 0);
        u8g2_DrawBox(u8g2, 0, y + m_offset, 2, h + 1);
        u8g2_SetDrawColor(u8g2, 1);
        u8g2_DrawBox(u8g2, 2, y + m_offset, 4, h + 1);
    }
}

int DragOnScrollableMenu::wheel(int count) {
    if (m_isDragging && count != 0) {
        while (count != 0) {
            if (count > 0 && m_current + 1 < m_subViews.size() && (m_drag == nullptr || m_drag(m_current, m_current + 1))) {
                swap(m_current, m_current + 1);
                m_current++;
                count--;
            } else if (count < 0 && m_current > 0 && (m_drag == nullptr || m_drag(m_current, m_current - 1))) {
                swap(m_current, m_current - 1);
                m_current--;
                count++;
            } else {
                break;
            }
        }
        return ScrollableMenu::wheel(0);;
    } else {
        return ScrollableMenu::wheel(count);
    }
}

void DragOnScrollableMenu::button(View::press_t press) {
    if (press == View::long_press) {
        m_isDragging = true;
        ScrollableMenu::button(press);
    } else if (m_isDragging && press == View::release) {
        m_isDragging = false;
    }
    ScrollableMenu::button(press);
}

void DragOnScrollableMenu::set_drag_cb(std::function<bool(size_t a, size_t b)> cb) {
    m_drag = cb;
}