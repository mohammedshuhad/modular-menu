#include "View/SecretNavigateView.hpp"

#include "esp_timer.h"

SecretNavigateView::SecretNavigateView(ViewManager &viewManager, View &parent, View &target, int numPresses, int64_t pressTime) :
    MimicView(parent), m_viewManager(viewManager), m_target(target),
    m_numPresses(numPresses), m_pressCount(0), m_pressTime(pressTime), m_startTime(0) {

}

void SecretNavigateView::button(View::press_t press) {
    MimicView::button(press);
    if (press == View::press) {
        int64_t now = esp_timer_get_time();
        int64_t timeDiff = now - m_startTime;
        m_startTime = now;

        if (timeDiff <= m_pressTime) {
            m_pressCount++;
        } else {
            m_pressCount = 0;
        }

        if (m_pressCount >= m_numPresses) {
            m_pressCount = 0;
            m_viewManager.navigate(&m_target);
        }
    }
}