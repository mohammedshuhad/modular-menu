#pragma once

#include "MenuItem.hpp"
#include "View/ViewManager.hpp"
#include "View/View.hpp"

#include <string>

/**
 * @brief MenuItem that navigates to a View when pressed
 *
 */
class NavigateMenuItem : public MenuItem {
public:
    /**
     * @brief Construct a new Navigate Menu Item object
     *
     * @param viewManager the ViewManager to navigate
     * @param target the View to navigate to
     * @param label the label to display
     */
    NavigateMenuItem(ViewManager &viewManager, View &target, std::string label);

    /**
     * @brief Overrides View
     *
     */
    virtual void draw(u8g2_t *u8g2, int y) override;

    /**
     * @brief Overrides View
     *
     */
    virtual int getHeight(void) override;

    /**
     * @brief Overrides MenuItem
     *
     */
    virtual void scroll(int scrollCount) override;

    /**
     * @brief Overrides MenuItem
     *
     */
    virtual bool buttonAction(View::press_t press) override;

    /**
     * @brief Overrides MenuItem
     *
     */
    virtual void startEditing(void) override;

    /**
     * @brief Overrides MenuItem
     *
     */
    virtual void stopEditing(void) override;
protected:
    ViewManager &m_viewManager;
    View &m_target;
    std::string m_label;
};