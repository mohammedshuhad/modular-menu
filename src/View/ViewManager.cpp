#include "View/ViewManager.hpp"

#include "esp_timer.h"
#include "esp_log.h"

#define TAG "ViewManager"

ViewManager::ViewManager(u8g2_t *u8g2) :
    u8g2(u8g2) {
}

void ViewManager::draw(void) {
    // static int64_t time0 = 0, time1 = 0, time2 = 0;
    // static int64_t time_count = 0;
    // static int64_t time_passed = 0;

    if (m_viewStack.size() > 0) {
        // int64_t t0 = esp_timer_get_time();
        u8g2_ClearBuffer(u8g2);
        // int64_t t1 = esp_timer_get_time();
        getCurrentView()->draw(u8g2, 0);
        // int64_t t2 = esp_timer_get_time();
        u8g2_SendBuffer(u8g2);
        // int64_t t3 = esp_timer_get_time();

        // time0 += t1 - t0;
        // time1 += t2 - t1;
        // time2 += t3 - t2;
        // time_count += 1;

        // if (t3 - time_passed >= 10000000) {
        //     ESP_LOGI(TAG, "Draw %lld times [%lldms, %lldms, %lldms]",
        //         time_count,
        //         time0 / time_count / 1000,
        //         time1 / time_count / 1000,
        //         time2 / time_count / 1000
        //     );
        //
        //     time_passed = t3;
        //     time0 = 0; time1 = 0; time2 = 0;
        //     time_count = 0;
        // }
    }
}

void ViewManager::wheel(int count) {
    if (m_viewStack.size() > 0) {
        getCurrentView()->wheel(count);
    }
}

void ViewManager::button(View::press_t press) {
    if (m_viewStack.size() > 0) {
        getCurrentView()->button(press);
    }
}

bool ViewManager::setInitialView(View *view) {
    if (m_viewStack.size() == 0) {
        m_viewStack.push_back(view);
        if (getCurrentView()->isSelectable()) {
            getCurrentView()->select();
        }
        return true;
    } else {
        return false;
    }
}

void ViewManager::navigate(View* view) {
    getCurrentView()->deselect();
    m_viewStack.push_back(view);
    getCurrentView()->select();
}

void ViewManager::back(void) {
    if (m_viewStack.size() > 1) {
        getCurrentView()->deselect();
        m_viewStack.pop_back();
        getCurrentView()->select();
    }
}

void ViewManager::backToRoot(void) {
    while (m_viewStack.size() > 1) {
        getCurrentView()->deselect();
        m_viewStack.pop_back();
        getCurrentView()->select();
    }
}

View *ViewManager::getCurrentView(void) {
    return m_viewStack.back();
}

int ViewManager::getDisplayWidth(void) {
    return u8g2_GetDisplayWidth(u8g2);
}

int ViewManager::getDisplayHeight(void) {
    return u8g2_GetDisplayHeight(u8g2);
}