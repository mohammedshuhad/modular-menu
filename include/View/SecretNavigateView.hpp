#pragma once

#include "MimicView.hpp"
#include "ViewManager.hpp"

/**
 * @brief MimicView that will navigate to a new view if it gets pressed times fast enough
 *
 */
class SecretNavigateView : public MimicView {
public:
    /**
     * @brief Construct a new Secret Navigate View object
     *
     * @param viewManager the ViewManager to navigate
     * @param parent the View to mimic
     * @param target the View to navigate to
     * @param numPresses the number of presses to wait for before navigating
     * @param pressTime the maximum amount of time between presses
     */
    SecretNavigateView(ViewManager &viewManager, View &parent, View &target, int numPresses, int64_t pressTime);

    /**
     * @brief Overrides View
     *
     */
    virtual void button(View::press_t press) override;
private:
    ViewManager &m_viewManager;
    View &m_target;
    int m_numPresses;
    int m_pressCount;
    int64_t m_pressTime;
    int64_t m_startTime;
};