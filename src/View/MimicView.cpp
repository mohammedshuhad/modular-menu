#include "View/MimicView.hpp"

MimicView::MimicView(View &parent) :
    m_parent(parent) {

}

void MimicView::draw(u8g2_t *u8g2, int y) {
    m_parent.draw(u8g2, y);
}

int MimicView::getDrawPriority(void) {
    return m_parent.getDrawPriority();
}

int MimicView::getHeight(void) {
    return m_parent.getHeight();
}

int MimicView::wheel(int count) {
    return m_parent.wheel(count);
}

void MimicView::button(View::press_t press) {
    m_parent.button(press);
}

bool MimicView::isSelectable(void) {
    return m_parent.isSelectable();
}

void MimicView::select(void) {
    m_parent.select();
}

void MimicView::deselect(void) {
    m_parent.deselect();
}
