#pragma once

#include "MenuItem.hpp"
#include "Data/MultiMenuData.hpp"

/**
 * @brief MenuItem to display a title and a value string on two line
 *        allows the string to be edited in multiple parts
 *
 */
class DoubleLineCharMultiMenuItem : public MenuItem {
public:
    /**
     * @brief Construct a new Double Line Char Multi Menu Item object
     *
     * @param title the title to display
     * @param data the data to display and edit
     * @param scrollResponse the ScrollResponse to use when editing
     * @param displayRight whether or not to display on the left or right
     */
    DoubleLineCharMultiMenuItem(std::string title, CharMultiMenuData &data, const ScrollResponse &scrollResponse, bool displayRight);

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
private:
    std::string m_title;
    CharMultiMenuData &m_data;
    bool m_displayRight;
};