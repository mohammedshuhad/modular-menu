#include "Item/NavigateMenuItem.hpp"

#include "Scroll/SimpleScrollResponse.hpp"

NavigateMenuItem::NavigateMenuItem(ViewManager &viewManager, View &target, std::string label) :
    MenuItem(true, false, SimpleScrollResponse::oneScroll), m_viewManager(viewManager), m_target(target), m_label(label) {

}

void NavigateMenuItem::draw(u8g2_t *u8g2, int y) {
    u8g2_SetDrawColor(u8g2, 1);

    u8g2_SetFont(u8g2, u8g2_font_6x10_tf);
    u8g2_DrawStr(u8g2, 2, y + 9, m_label.c_str());

    u8g2_SetFont(u8g2, u8g2_font_open_iconic_arrow_1x_t);
    u8g2_DrawStr(u8g2, u8g2_GetDisplayWidth(u8g2) - 12, y + 10, "\x4e");

    if(m_isSelected) {
        u8g2_DrawFrame(u8g2, 0, y, u8g2_GetDisplayWidth(u8g2) - 4, 11);
    }
}

int NavigateMenuItem::getHeight(void) {
    return 10;
}

void NavigateMenuItem::scroll(int scrollCount) {
    // DOES NOTHING
}

bool NavigateMenuItem::buttonAction(View::press_t press) {
    if (press == View::press) {
        m_viewManager.navigate(&m_target);
    }
    return true;
}

void NavigateMenuItem::startEditing(void) {
    // DOES NOTHING
}

void NavigateMenuItem::stopEditing(void){
    // DOES NOTHING
};
