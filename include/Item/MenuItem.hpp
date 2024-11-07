#pragma once

#include "View/View.hpp"
#include "Scroll/ScrollResponse.hpp"

/**
 * @brief Class to represent Items inside a Menu
 *
 */
class MenuItem : public View {
public:
    /**
     * @brief Construct a new Menu Item object
     *
     * @param isSelectable whether or not the MenuItem can be selected
     * @param isEditable whether or not the MenuItem can be edited
     * @param scrollResponse the ScrollResponse to use when editing
     */
    MenuItem(bool isSelectable, bool isEditable, const ScrollResponse &scrollResponse);

    /**
     * @brief Overrides View
     *
     */
    virtual void draw(u8g2_t *u8g2, int y) = 0;

    /**
     * @brief Overrides View
     *
     */
    virtual int getDrawPriority(void) override;

    /**
     * @brief Overrides View
     *
     */
    virtual int getHeight(void) = 0;

    /**
     * @brief Overrides View
     *
     */
    virtual int wheel(int count) override final;

    /**
     * @brief Overrides View
     *
     */
    virtual void button(View::press_t press) override final;

    /**
     * @brief Overrides View
     *
     */
    virtual bool isSelectable(void) override final;

    /**
     * @brief Returns whether or not the MenuItem can be edited
     *
     * @return true can be edited
     * @return false cannot be edited
     */
    bool isEditable(void);

    /**
     * @brief Returns whether or not the MenuItem is selected
     *
     * @return true is selected
     * @return false is not selected
     */
    bool isSelected(void);

    /**
     * @brief Returns whether or not the MenuItem is currently being edited
     *
     * @return true is currently being edited
     * @return false is not currently being edited
     */
    bool isEditing(void);

    /**
     * @brief Set whether or not the MenuItem can be selected
     *
     * @param selectable whether or not the MenuItem can be selected
     */
    void setIsSelectable(bool selectable);

    /**
     * @brief Set whether or not the MenuItem can be edited
     *
     * @param selectable whether or not the MenuItem can be edited
     */
    void setIsEditable(bool editable);

    /**
     * @brief Overrides View
     *
     */
    virtual void select(void) override final;

    /**
     * @brief Overrides View
     *
     */
    virtual void deselect(void) override final;

    /**
     * @brief Called when the MenuItem is currently being edited and a wheel event is received
     * @note the scrollCount is modified by the saved ScrollResponse
     *
     * @param scrollCount the abount to scroll by
     */
    virtual void scroll(int scrollCount) = 0;

    /**
     * @brief Called when the MenuItem is currently being edited and a button event is received
     *        or when the MenuItem cannot be edited and is selected and a buttin event is received
     *
     * @param press the type of button event
     * @return true stop editing
     * @return false don't stop editing
     */
    virtual bool buttonAction(View::press_t press) = 0;

    /**
     * @brief Called when the MenuItem starts being edited
     *
     */
    virtual void startEditing(void) = 0;

    /**
     * @brief Called when the MenuItem stops being edited
     *
     */
    virtual void stopEditing(void) = 0;
protected:
    bool m_isSelectable;
    bool m_isEditable;
    bool m_isSelected;
    bool m_isEditing;

    const ScrollResponse &m_scrollResponse;
    uint64_t m_lastScrollTime;
};