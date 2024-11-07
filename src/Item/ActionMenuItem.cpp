#include "Item/ActionMenuItem.hpp"

#include "Scroll/SimpleScrollResponse.hpp"

ActionMenuItem::ActionMenuItem(ActionMenuData &data) :
    MenuItem(true, false, SimpleScrollResponse::oneScroll), m_data(data) {

}

void ActionMenuItem::draw(u8g2_t *u8g2, int y) {
    u8g2_SetDrawColor(u8g2, 1);

    u8g2_SetFont(u8g2, u8g2_font_6x10_tf);
    u8g2_DrawStr(u8g2, 2, y + 9, m_data.key().c_str());

    if(m_isSelected) {
        u8g2_DrawFrame(u8g2, 0, y, u8g2_GetDisplayWidth(u8g2) - 4, 11);
    }
}

int ActionMenuItem::getHeight(void) {
    return 10;
}

void ActionMenuItem::scroll(int scrollCount) {
    // DOES NOTHING
}

bool ActionMenuItem::buttonAction(View::press_t press) {
    if (press == View::press) {
        m_data.action();
    }
    return false;
}

void ActionMenuItem::startEditing(void) {
    // DOES NOTHING
}

void ActionMenuItem::stopEditing(void) {
    // DOES NOTHING
}