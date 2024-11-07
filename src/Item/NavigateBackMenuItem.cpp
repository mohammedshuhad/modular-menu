#include "Item/NavigateBackMenuItem.hpp"

#include "Scroll/SimpleScrollResponse.hpp"

NavigateBackMenuItem::NavigateBackMenuItem(ViewManager &viewManager, std::string label) :
    MenuItem(true, false, SimpleScrollResponse::oneScroll), m_viewManager(viewManager), m_label(label) {

}

void NavigateBackMenuItem::draw(u8g2_t *u8g2, int y) {
    u8g2_SetDrawColor(u8g2, 1);

    u8g2_SetFont(u8g2, u8g2_font_6x10_tf);
    u8g2_DrawStr(u8g2, 9, y + 9, m_label.c_str());

    u8g2_SetFont(u8g2, u8g2_font_open_iconic_arrow_1x_t);
    u8g2_DrawStr(u8g2, 0, y + 10, "\x4d");

    if(m_isSelected) {
        u8g2_DrawFrame(u8g2, 0, y, u8g2_GetDisplayWidth(u8g2) - 4, 11);
    }
}

int NavigateBackMenuItem::getHeight(void) {
    return 10;
}

void NavigateBackMenuItem::scroll(int scrollCount) {
    // DOES NOTHING
}

bool NavigateBackMenuItem::buttonAction(View::press_t press) {
    if (press == View::press) {
        m_viewManager.back();
        return true;
    } else {
        return false;
    }
}

void NavigateBackMenuItem::startEditing(void) {
    // DOES NOTHING
}

void NavigateBackMenuItem::stopEditing(void) {
    // DOES NOTHING
}