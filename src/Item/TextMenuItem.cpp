#include "Item/TextMenuItem.hpp"

#include "Scroll/SimpleScrollResponse.hpp"

TextMenuItem::TextMenuItem(std::string label, bool selectable) :
    MenuItem(selectable, false, SimpleScrollResponse::oneScroll), m_label(label) {

}

void TextMenuItem::draw(u8g2_t *u8g2, int y) {
    u8g2_SetDrawColor(u8g2, 1);

    u8g2_SetFont(u8g2, u8g2_font_6x10_tf);
    u8g2_DrawStr(u8g2, 2, y + 9, m_label.c_str());

    if(m_isSelected) {
        u8g2_DrawFrame(u8g2, 0, y, u8g2_GetDisplayWidth(u8g2) - 4, 11);
    }
}

int TextMenuItem::getHeight(void) {
    return 10;
}

void TextMenuItem::scroll(int scrollCount) {
    // DOES NOTHING
}

bool TextMenuItem::buttonAction(View::press_t press) {
    // DOES NOTHING
    return true;
}

void TextMenuItem::startEditing(void) {
    // DOES NOTHING
}

void TextMenuItem::stopEditing(void) {
    // DOES NOTHING
}