#pragma once

#include "View.hpp"

#include <vector>

/**
 * @brief Class to manage the Views
 *
 */
class ViewManager {
public:
    /**
     * @brief Construct a new View Manager object
     *
     * @param u8g2 the u8g2 object to store inside the ViewManager
     */
    ViewManager(u8g2_t *u8g2);

    /**
     * @brief Draw the current View to the screen
     *
     */
    void draw(void);

    /**
     * @brief Send a wheel event to the current View
     *
     * @param count the number of ticks (up or down)
     */
    void wheel(int count);

    /**
     * @brief Send a button event to the current View
     *
     * @param press the type of button event
     */
    void button(View::press_t press);

    /**
     * @brief Set the Initial View
     *
     * @param view the View to draw initially
     * @return true Success the View was set
     * @return false Fail there is already an initial View
     */
    bool setInitialView(View *view);

    /**
     * @brief Navigate to a new View
     *
     * @param view the View to navigate to
     */
    void navigate(View *view);

    /**
     * @brief Navigate back to the previous view
     *
     */
    void back(void);

    /**
     * @brief Navigate back to the initial View
     *
     */
    void backToRoot(void);

    /**
     * @brief Returns the current View
     *
     * @return View* the current View
     */
    View *getCurrentView(void);

    /**
     * @brief Returns the width of the display
     *
     * @return int the width of the display
     */
    int getDisplayWidth(void);

    /**
     * @brief Returns the height of the display
     *
     * @return int the height of the display
     */
    int getDisplayHeight(void);
private:
    u8g2_t *u8g2;
    std::vector<View*> m_viewStack;
};