#pragma once

#include "MenuItem.hpp"
#include "Data/MenuData.hpp"

/**
 * @brief MenuItem to display a title and a value string on two line
 *
 */
class DoubleLineStringMenuItem : public MenuItem {
public:
    /**
     * @brief Construct a new Double Line String Menu Item object
     *
     * @param title the title to display
     * @param data the data to display and edit
     * @param scrollResponse the ScrollResponse to use when editing
     * @param displayRight whether or not to display on the left or right
     */
    DoubleLineStringMenuItem(std::string title, StringMenuData &data, const ScrollResponse &scrollResponse, bool displayRight);

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
    std::string m_title;
    StringMenuData &m_data;
    bool m_displayRight;
};