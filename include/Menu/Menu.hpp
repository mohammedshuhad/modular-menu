#pragma once

#include "View/View.hpp"

#include <vector>

/**
 * @brief View to display multiple sub Views
 *
 */
class Menu : public View {
public:
    /**
     * @brief Construct a new Menu object
     *
     */
    Menu(void);

    /**
     * @brief Overrides View
     *
     */
    virtual void draw(u8g2_t *u8g2, int y) override;

    /**
     * @brief Overrides View
     *
     */
    virtual int getDrawPriority(void) override;

    /**
     * @brief Overrides View
     *
     */
    virtual int getHeight(void) override;

    /**
     * @brief Overrides View
     *
     */
    virtual int wheel(int count) override;

    /**
     * @brief Overrides View
     *
     */
    virtual void button(View::press_t press) override;

    /**
     * @brief Overrides View
     *
     */
    virtual bool isSelectable(void) override;

    /**
     * @brief Overrides View
     *
     */
    virtual void select(void) override;

    /**
     * @brief Overrides View
     *
     */
    virtual void deselect(void) override;

    /**
     * @brief Adds a new View to the Menu
     *
     * @param view the View to add
     */
    void addSubView(View* view);

    /**
     * @brief Removes a View from the menu
     *
     * @param view the View to remove
     */
    void removeSubView(View* view);

    /**
     * @brief Returns the currently selected View object
     * @note returns NULL when there is no View Selected
     *
     * @return View* the currently selected View
     */
    View* getCurrentView(void);

    /**
     * @brief Resets the current view to the first item
     *
     */
    void resetCurrentView(void);

    /**
     * @brief Returns the number of sub Views in the Menu
     *
     * @return size_t the number of sub Views in the Menu
     */
    size_t getNumSubViews(void);

    /**
     * @brief Returns the sub View at the index
     * @note returns NULL of there is no View at the index or the index is out of bounds
     *
     * @param index the index to get the sub View from
     * @return View* the sub View at the index
     */
    View* getSubView(size_t index);
protected:
    /**
     * @brief Returns the next View that can be selected
     * @note Returns startingIndex if there is no selectable View
     *
     * @param startingIndex the index to start looking at
     * @return size_t the index of the next View that can be selected
     */
    size_t getNextSelectableView(size_t startingIndex);

    /**
     * @brief Returns the previous View that can be selected
     * @note Returns startingIndex if there is no selectable View
     *
     * @param startingIndex the index to start looking at
     * @return size_t the index of the previous View that can be selected
     */
    size_t getPrevSelectableView(size_t startingIndex);

    /**
     * @brief Begins drawing the sub Views starting at the index <start>
     *
     * @param u8g2 instance of u8g2 to render to
     * @param y offset into the screen to render
     * @param start index of first subView to render
     */
    void drawFrom(u8g2_t *u8g2, int y, size_t start);

    /**
     * @brief Swaps the sub Views at index <a> and <b>
     *
     * @param a the first index to swap
     * @param b the second index to swap
     */
    void swap(size_t a, size_t b);

    std::vector<View*> m_subViews;
    bool m_isSelected;
    size_t m_current;
};