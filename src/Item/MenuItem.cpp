#include "Item/MenuItem.hpp"

#include "esp_timer.h"

MenuItem::MenuItem(bool isSelectable, bool isEditable, const ScrollResponse &scrollResponse) :
    m_isSelectable(isSelectable), m_isEditable(isEditable), m_isSelected(false), m_isEditing(false), m_scrollResponse(scrollResponse), m_lastScrollTime(0) {

}

int MenuItem::getDrawPriority(void) {
    return 1;
}

int MenuItem::wheel(int count) {
    if (m_isEditing && count != 0) {
        int absCount = count > 0 ? count : -count;

        int64_t now = esp_timer_get_time();
        int timeSinceLastScroll = (int)((now - m_lastScrollTime) / 1000);
        m_lastScrollTime = now;

        int sizeScroll = count * m_scrollResponse.getScroll(timeSinceLastScroll / absCount);

        scroll(sizeScroll);
        return 0;
    } else {
        return count;
    }
}

void MenuItem::button(View::press_t press) {
    if (m_isEditable) {
        if (m_isEditing) {
            if (buttonAction(press)) {
                m_isEditing = false;
                stopEditing();
            }
        } else if (press == View::press) {
            m_isEditing = true;
            startEditing();
        }
    } else {
        buttonAction(press);
    }
}

bool MenuItem::isSelectable(void) {
    return m_isSelectable;
}

bool MenuItem::isEditable(void) {
    return m_isEditable;
}

bool MenuItem::isSelected(void) {
    return m_isSelected;
}

bool MenuItem::isEditing(void) {
    return m_isEditing;
}

void MenuItem::setIsSelectable(bool selectable) {
    m_isSelectable = selectable;
    if (!m_isSelectable && m_isSelected) {
        m_isSelected = false;
    }
}

void MenuItem::setIsEditable(bool editable) {
    m_isEditable = editable;
}

void MenuItem::select(void) {
    m_isSelected = true;
}

void MenuItem::deselect(void) {
    m_isSelected = false;
}