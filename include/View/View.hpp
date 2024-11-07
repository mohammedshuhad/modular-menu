#pragma once

#include "u8g2.h"

/**
 * @brief Interface for all objects that can be drawn by the ViewManager
 *
 */
class View {
public:
    /**
     * @brief press event types
     *
     */
    enum press_t {
        press,
        release,
        long_press
    };

    /**
     * @brief virtual destructor
     *
     */
    virtual ~View() {};

    /**
     * @brief Render the View to the screen
     *
     * @param u8g2 instance of u8g2 to render to
     * @param y offset into the screen to render
     */
    virtual void draw(u8g2_t *u8g2, int y) = 0;

    /**
     * @brief number representing when to draw this View
     * @note Higher numbers get draws first
     *
     * @return int the draw priority of this View
     */
    virtual int getDrawPriority(void) = 0;

    /**
     * @brief Returns how tall the View is
     *
     * @return int the height of the View
     */
    virtual int getHeight(void) = 0;

    /**
     * @brief Send wheel events to the View
     *
     * @param count the number of ticks (up or down)
     * @return int return number of unused ticks
     */
    virtual int wheel(int count) = 0;

    /**
     * @brief Send button events to the View
     *
     * @param press the type of button event
     */
    virtual void button(press_t press) = 0;

    /**
     * @brief Returns whether or not the View can be selected
     *
     * @return true can be selected
     * @return false cannot be selected
     */
    virtual bool isSelectable(void) = 0;

    /**
     * @brief Called when the View is selected
     *
     */
    virtual void select(void) = 0;

    /**
     * @brief Called when the View is deselected
     *
     */
    virtual void deselect(void) = 0;
};