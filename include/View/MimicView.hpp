#pragma once

#include "View.hpp"

/**
 * @brief View that mimics another view
 *
 */
class MimicView : public View {
public:
    /**
     * @brief Construct a new Mimic View object
     *
     * @param parent the view to mimic
     */
    MimicView(View &parent);

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
protected:
    View &m_parent;
};