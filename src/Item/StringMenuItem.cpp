#include "Item/StringMenuItem.hpp"

StringMenuItem::StringMenuItem(StringMenuData &data, const ScrollResponse &scrollResponse) :
    MenuItem(true, true, scrollResponse), m_data(data), m_alwaysCommit(false) {

}

void StringMenuItem::draw(u8g2_t *u8g2, int y) {
    u8g2_SetDrawColor(u8g2, 1);
    u8g2_SetFontMode(u8g2, 1);
    u8g2_SetFont(u8g2, u8g2_font_6x10_tf);

    std::string str = m_data.value();
    u8g2_DrawStr(u8g2, 2, y + 9, str.c_str());

    if (m_isEditing) {
        u8g2_SetDrawColor(u8g2, 2);
        u8g2_DrawBox(u8g2, 0, y, u8g2_GetDisplayWidth(u8g2) - 4, 11);
    } else if (m_isSelected) {
        u8g2_SetDrawColor(u8g2, 1);
        u8g2_DrawFrame(u8g2, 0, y, u8g2_GetDisplayWidth(u8g2) - 4, 11);
    }
}

int StringMenuItem::getHeight(void) {
    return 10;
}

void StringMenuItem::scroll(int scrollCount) {
    m_data.mutate(scrollCount);
    if (m_alwaysCommit) {
        m_data.commit();
    }
}

bool StringMenuItem::buttonAction(View::press_t press) {
    if (press == View::press || press == View::long_press) {
        return true;
    } else {
        return false;
    }
}

void StringMenuItem::startEditing(void) {
    // DOES NOTHING
}

void StringMenuItem::stopEditing(void) {
    m_data.commit();
}

void StringMenuItem::setAlwaysCommit(void) {
    m_alwaysCommit = true;
}
