#pragma once

#include "MenuItem.hpp"
#include "Data/ActionMenuData.hpp"

/**
 * @brief MenuItem that displays a label and has a press action
 *
 */
class ActionMenuItem : public MenuItem {
public:
    /**
     * @brief Construct a new Action Menu Item object
     *
     * @param data the label to display and the action to take when pressed
     */
    ActionMenuItem(ActionMenuData &data);

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
    ActionMenuData &m_data;
};