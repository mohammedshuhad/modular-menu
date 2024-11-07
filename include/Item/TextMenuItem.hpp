#pragma once

#include "MenuItem.hpp"

#include <string>

/**
 * @brief MenuItem that just displays some text
 *
 */
class TextMenuItem : public MenuItem {
public:
    /**
     * @brief Construct a new Text Menu Item object
     *
     * @param title the label to display
     * @param selectable whether or not the MenuItem is selectable
     */
    TextMenuItem(std::string label, bool selectable);

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
    std::string m_label;
};