#include "Item/SingleLineStringDisplayMenuItem.hpp"

SingleLineStringDisplayMenuItem::SingleLineStringDisplayMenuItem(std::string title, StringMenuData &data, const ScrollResponse &scrollResponse) :
    MenuItem(true, true, scrollResponse), m_title(title), m_data(data), m_alwaysCommit(false) {

}

void SingleLineStringDisplayMenuItem::draw(u8g2_t *u8g2, int y) {
    u8g2_SetDrawColor(u8g2, 1);

    u8g2_SetFont(u8g2, u8g2_font_6x10_tf);
    u8g2_DrawStr(u8g2, 2, y + 9, m_title.c_str());

    std::string string = m_data.value();
    const char* str = string.c_str();

    int width = u8g2_GetStrWidth(u8g2, str);

    u8g2_DrawStr(u8g2, u8g2_GetDisplayWidth(u8g2) - 6 - width, y + 9, str);

    // if (m_isEditing)
    // {
    //     u8g2_SetDrawColor(u8g2, 2);
    //     u8g2_DrawBox(u8g2, 0, y, u8g2_GetDisplayWidth(u8g2) - 4, 11);
    // }
    if (m_isSelected)
    {
        u8g2_SetDrawColor(u8g2, 1);
        u8g2_DrawFrame(u8g2, 0, y, u8g2_GetDisplayWidth(u8g2) - 4, 11);
    }
}

int SingleLineStringDisplayMenuItem::getHeight(void) {
    return 10;
}

void SingleLineStringDisplayMenuItem::scroll(int scrollCount) {
    // m_data.mutate(scrollCount);
    // if (m_alwaysCommit) {
    //     m_data.commit();
    // }
}

bool SingleLineStringDisplayMenuItem::buttonAction(View::press_t press) {
    // if (press == View::press || press == View::long_press) {
    //     return true;
    // } else {
    //     return false;
    // }
    return true;
}

void SingleLineStringDisplayMenuItem::startEditing(void) {
    // DOES NOTHING
}

void SingleLineStringDisplayMenuItem::stopEditing(void) {
    // m_data.commit();
}

void SingleLineStringDisplayMenuItem::setAlwaysCommit(void) {
    // m_alwaysCommit = true;
}
