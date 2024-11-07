#include "Item/DoubleLineStringMenuItem.hpp"

DoubleLineStringMenuItem::DoubleLineStringMenuItem(std::string title, StringMenuData &data, const ScrollResponse &scrollResponse, bool displayRight) :
    MenuItem(true, true, scrollResponse), m_title(title), m_data(data), m_displayRight(displayRight) {

}

void DoubleLineStringMenuItem::draw(u8g2_t *u8g2, int y) {
    u8g2_SetDrawColor(u8g2, 1);

    u8g2_SetFont(u8g2, u8g2_font_6x10_tf);
    u8g2_DrawStr(u8g2, 2, y + 9, m_title.c_str());

    std::string string = m_data.value();
    const char* str = string.c_str();

    int width = u8g2_GetStrWidth(u8g2, str);

    int x = m_displayRight ? u8g2_GetDisplayWidth(u8g2) - 6 - width : 2;
    u8g2_DrawStr(u8g2, x, y + 19, str);

    if (m_isEditing) {
        u8g2_SetDrawColor(u8g2, 2);
        u8g2_DrawBox(u8g2, 0, y, u8g2_GetDisplayWidth(u8g2) - 4, 21);
    } else if (m_isSelected) {
        u8g2_SetDrawColor(u8g2, 1);
        u8g2_DrawFrame(u8g2, 0, y, u8g2_GetDisplayWidth(u8g2) - 4, 21);
    }
}

int DoubleLineStringMenuItem::getHeight(void) {
    return 20;
}

void DoubleLineStringMenuItem::scroll(int scrollCount) {
    m_data.mutate(scrollCount);
}

bool DoubleLineStringMenuItem::buttonAction(View::press_t press) {
    if (press == View::press || press == View::long_press) {
        return true;
    } else {
        return false;
    }
}

void DoubleLineStringMenuItem::startEditing(void) {
    // DOES NOTHING
}

void DoubleLineStringMenuItem::stopEditing(void) {
    m_data.commit();
}
