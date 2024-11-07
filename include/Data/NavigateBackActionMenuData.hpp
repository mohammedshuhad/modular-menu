#pragma once

#include "ActionMenuData.hpp"
#include "View/ViewManager.hpp"
#include "View/View.hpp"

/**
 * @brief ActionMenuData to navigate back when pressed
 *
 */
class NavigateBackActionMenuData : public ActionMenuData {
public:
    /**
     * @brief Construct a new Navigate Back Action Menu Data object
     *
     * @param viewManager the viewManager to navigate
     * @param label the label to display
     */
    NavigateBackActionMenuData(ViewManager &viewManager, std::string label);

    /**
     * @brief Overrides ActionMenuData
     *
     */
    virtual std::string key(void) override;

    /**
     * @brief Overrides ActionMenuData
     *
     */
    virtual void action(void) override;
protected:
    ViewManager &m_viewManager;
    std::string m_label;
};