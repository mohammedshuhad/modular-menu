#pragma once

#include "MenuItem.hpp"
#include "Data/MenuData.hpp"

/**
 * @brief MenuItem to display a title and a value string on one line
 *
 */
class StringMenuItem : public MenuItem {
public:
    /**
     * @brief Construct a new String Menu Item object
     *
     * @param data the data to display and edit
     * @param scrollResponse the ScrollResponse to use when editing
     */
    StringMenuItem(StringMenuData &data, const ScrollResponse &scrollResponse);

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
     * @brief Make commit be called after every mutate call
     *
     */
    void setAlwaysCommit(void);
protected:
    StringMenuData &m_data;
    bool m_alwaysCommit;
};