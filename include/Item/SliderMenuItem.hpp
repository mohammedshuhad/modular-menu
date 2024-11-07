#pragma once

#include "MenuItem.hpp"
#include "Data/ScaledMenuData.hpp"

#include <string>

/**
 * @brief MenuItem to display a title and a slider representing an integer value
 *
 */
class SliderMenuItem : public MenuItem {
public:
    /**
     * @brief Construct a new Slider Menu Item object
     *
     * @param title the title to display
     * @param data a the data to display and edit
     * @param scrollResponse the ScrollResponse to use when editing
     */
    SliderMenuItem(std::string title, ScaledIntMenuData &data, const ScrollResponse &scrollResponse);

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

    /**
     * @brief Changes the title to display
     *
     * @param title the new title to display
     */
    void setTitle(std::string title);
protected:
    std::string m_title;
    ScaledIntMenuData &m_data;
};