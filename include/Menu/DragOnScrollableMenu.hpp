#pragma once

#include "ScrollableMenu.hpp"

#include <functional>

/**
 * @brief Menu that can be scrolled and the items can be dragged by long pressing
 *
 */
class DragOnScrollableMenu : public ScrollableMenu {
public:
    /**
     * @brief Construct a new Drag On Scrollable Menu object
     *
     * @param height the height of the Menu
     */
    DragOnScrollableMenu(int height);

    /**
     * @brief Overrides ScrollableMenu
     *
     */
    virtual void draw(u8g2_t *u8g2, int y) override;

    /**
     * @brief Overrides ScrollableMenu
     *
     */
    virtual int wheel(int count) override;

    /**
     * @brief Overrides ScrollableMenu
     *
     */
    virtual void button(View::press_t press) override;

    /**
     * @brief Set the callback when dragging
     * @note the swap only happens if the callback return true
     *
     * @param cb the callback that gets called before every swap
     */
    void set_drag_cb(std::function<bool(size_t a, size_t b)> cb);
protected:
    bool m_isDragging;
    std::function<bool(size_t a, size_t b)> m_drag;
};