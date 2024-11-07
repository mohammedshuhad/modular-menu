#include "Menu/ScrollableMenu.hpp"

#include "esp_log.h"

#define TAG "ScrollableMenu"

ScrollableMenu::ScrollableMenu(int height) :
    m_scrollPosition(0), m_height(height), m_offset(0) {

}

void ScrollableMenu::draw(u8g2_t *u8g2, int y) {
    if (m_offset > 0 && m_scrollPosition > 0) {
        Menu::drawFrom(u8g2, y + m_offset - m_subViews[m_scrollPosition - 1]->getHeight(), m_scrollPosition - 1);
    } else {
        Menu::drawFrom(u8g2, y + m_offset, m_scrollPosition);
    }

    u8g2_SetDrawColor(u8g2, 0);
    u8g2_DrawBox(u8g2, 0, 0, u8g2_GetDisplayWidth(u8g2), y);
    u8g2_DrawBox(u8g2, 0, y + m_height, u8g2_GetDisplayWidth(u8g2), u8g2_GetDisplayHeight(u8g2));
    u8g2_DrawBox(u8g2, u8g2_GetDisplayWidth(u8g2) - 2, y, 2, m_height);

    int start = 0;
    for (size_t i = 0; i < m_scrollPosition; i++)
        start += m_subViews[i]->getHeight();
    int end = start;
    for (size_t i = m_scrollPosition; i < m_subViews.size(); i++)
        end += m_subViews[i]->getHeight();

    end = end < 1 ? 1 : end;

    int barOffset = (start - m_offset) * (m_height - 4) / end;
    int barHeight = m_height * (m_height - 4) / end;

    barHeight = barHeight < 1 ? 1 : barHeight > m_height - 4 ? m_height - 4 : barHeight;

    u8g2_SetDrawColor(u8g2, 1);
    u8g2_DrawBox(u8g2, u8g2_GetDisplayWidth(u8g2) - 2, y, 2, 1);
    u8g2_DrawBox(u8g2, u8g2_GetDisplayWidth(u8g2) - 2, y + m_height - 1, 2, 1);
    u8g2_DrawBox(u8g2, u8g2_GetDisplayWidth(u8g2) - 2, y + 2 + barOffset, 2, barHeight);
}

int ScrollableMenu::getDrawPriority(void) {
    return 2;
}

int ScrollableMenu::getHeight(void) {
    return m_height;
}

int ScrollableMenu::wheel(int count) {
    count = Menu::wheel(count);

    if (m_scrollPosition < m_current) {
        int height = 0;
        for (size_t i = 0; i <= m_current; i++) {
            size_t index = m_current - i;
            height += m_subViews[index]->getHeight();
            if (height > m_height && index + 1 < m_subViews.size()) {
                if (m_scrollPosition < index + 1) {
                    m_scrollPosition = index + 1;
                    m_offset = m_height - (height - m_subViews[index]->getHeight()) - 1;
                }
                break;
            }
        }
    } else if (m_scrollPosition > m_current) {
        m_scrollPosition = m_current;
        m_offset = 0;
    }

    return count;
}

int ScrollableMenu::getContentHeight(void) {
    return Menu::getHeight();
}