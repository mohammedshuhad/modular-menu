#include "Item/SliderMenuItem.hpp"

SliderMenuItem::SliderMenuItem(std::string title, ScaledIntMenuData &data, const ScrollResponse &scrollResponse) :
    MenuItem(true, true, scrollResponse), m_title(title), m_data(data) {

}

void SliderMenuItem::draw(u8g2_t *u8g2, int y) {
    u8g2_SetDrawColor(u8g2, 1);

    u8g2_SetFont(u8g2, u8g2_font_6x10_tf);
    u8g2_DrawStr(u8g2, 2, y + 9, m_title.c_str());

    if (!m_isEditing) {
        u8g2_DrawFrame(u8g2, 1, y + 10, u8g2_GetDisplayWidth(u8g2) - 6, 10);
    }

    char buf[16];
    sprintf(buf, "%d", m_data.value());
    int width = u8g2_GetStrWidth(u8g2, buf);

    u8g2_DrawStr(u8g2, (u8g2_GetDisplayWidth(u8g2) - 4) / 2 - width / 2, y + 19, buf);

    u8g2_SetDrawColor(u8g2, 2);
    u8g2_DrawBox(u8g2, 2, y + 11, m_data.scaled_value(0, u8g2_GetDisplayWidth(u8g2) - 8), 8);

    if (m_isEditing) {
        u8g2_SetDrawColor(u8g2, 2);
        u8g2_DrawBox(u8g2, 0, y, u8g2_GetDisplayWidth(u8g2) - 4, 10);
    }
    if (m_isSelected) {
        u8g2_SetDrawColor(u8g2, 1);
        u8g2_DrawFrame(u8g2, 0, y, u8g2_GetDisplayWidth(u8g2) - 4, 21);
    }
}

int SliderMenuItem::getHeight(void) {
    return 20;
}

void SliderMenuItem::scroll(int scrollCount) {
    m_data.mutate(scrollCount);
    m_data.commit();
}

bool SliderMenuItem::buttonAction(View::press_t press) {
    if (press == View::press || press == View::long_press) {
        return true;
    } else {
        return false;
    }
}

void SliderMenuItem::startEditing(void) {
    // DOES NOTHING
}

void SliderMenuItem::stopEditing(void) {
    // DOES NOTHING
}

void SliderMenuItem::setTitle(std::string title) {
    m_title = title;
}