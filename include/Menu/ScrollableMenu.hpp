#pragma once

#include "Menu/Menu.hpp"

/**
 * @brief Menu that can be scrolled allowing more elements to be seen by a user
 *
 */
class ScrollableMenu : public Menu {
public:
    /**
     * @brief Construct a new Scrollable Menu object
     *
     * @param height the height of the Menu
     */
    ScrollableMenu(int height);

    /**
     * @brief Overrides Menu
     *
     */
    virtual void draw(u8g2_t *u8g2, int y) override;

    /**
     * @brief Overrides Menu
     *
     */
    virtual int getDrawPriority(void) override;

    /**
     * @brief Overrides Menu
     *
     */
    virtual int getHeight(void) override;

    /**
     * @brief Overrides Menu
     *
     */
    virtual int wheel(int count) override;

    /**
     * @brief Returns the total height of all sub Views
     *
     * @return int the total height of all sub Views
     */
    int getContentHeight(void);
protected:
    int m_scrollPosition;
    int m_height;
    int m_offset;
};