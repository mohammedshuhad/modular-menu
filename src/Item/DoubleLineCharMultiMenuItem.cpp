#include "Item/DoubleLineCharMultiMenuItem.hpp"

DoubleLineCharMultiMenuItem::DoubleLineCharMultiMenuItem(std::string title, CharMultiMenuData &data, const ScrollResponse &scrollResponse, bool displayRight) :
    MenuItem(true, true, scrollResponse), m_title(title), m_data(data), m_displayRight(displayRight) {

}

void DoubleLineCharMultiMenuItem::draw(u8g2_t *u8g2, int y) {
    u8g2_SetDrawColor(u8g2, 2);

    u8g2_SetFont(u8g2, u8g2_font_6x10_tf);
    u8g2_DrawStr(u8g2, 2, y + 9, m_title.c_str());

    int size = m_data.size();
    int index = m_data.index();

    if (m_displayRight) {
        int x = u8g2_GetDisplayWidth(u8g2) - 6;
        for (int i = size - 1; i >= 0; i--) {
            char ch = m_data.value_at(i);
            int width = u8g2_GetGlyphWidth(u8g2, ch);
            x -= width;
            u8g2_DrawGlyph(u8g2, x, y + 19, ch);
            if (m_isEditing && index == i) {
                u8g2_DrawBox(u8g2, x - 1, y + 10, width + 1, 10);
            }
        }
    } else {
        int x = 2;
        for (int i = 0; i < size; i++) {
            char ch = m_data.value_at(i);
            int width = u8g2_GetGlyphWidth(u8g2, ch);
            u8g2_DrawGlyph(u8g2, x, y + 19, ch);
            if (m_isEditing && index == i) {
                u8g2_DrawBox(u8g2, x - 1, y + 10, width + 1, 10);
            }
            x += width;
        }
    }

    if (m_isSelected) {
        u8g2_SetDrawColor(u8g2, 1);
        u8g2_DrawFrame(u8g2, 0, y, u8g2_GetDisplayWidth(u8g2) - 4, 21);
    }
}

int DoubleLineCharMultiMenuItem::getHeight(void) {
    return 20;
}

void DoubleLineCharMultiMenuItem::scroll(int scrollCount) {
    m_data.mutate(scrollCount);
}

bool DoubleLineCharMultiMenuItem::buttonAction(View::press_t press) {
    if (press == View::press || press == View::long_press) {
        return m_data.next();
    } else {
        return false;
    }
}

void DoubleLineCharMultiMenuItem::startEditing(void) {
    // DOES NOTHING
}

void DoubleLineCharMultiMenuItem::stopEditing(void) {
    m_data.commit();
}
