#pragma once

#include <string>

/**
 * @brief Interface to store a title and action to be used by MenuItems
 *
 */
class ActionMenuData {
public:
    /**
     * @brief virtual destructor
     *
     */
    virtual ~ActionMenuData() {}

    /**
     * @brief Returns a short string title for the action
     *
     * @return std::string
     */
    virtual std::string key(void) = 0;

    /**
     * @brief The action to be performed
     *
     */
    virtual void action(void) = 0;
};