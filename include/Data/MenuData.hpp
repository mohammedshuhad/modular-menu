#pragma once

/**
 * @brief Interface to hold data that can be manipulated and saved to external sources
 *
 * @tparam T the type of data to store
 */
template <typename T>
class MenuData {
public:
    /**
     * @brief virtual destructor
     *
     */
    virtual ~MenuData() {}

    /**
     * @brief Returns the stored values
     *
     * @return T the stored value
     */
    virtual T value(void) = 0;

    /**
     * @brief Alters the stored value
     *
     * @param amt the amount to alter by
     */
    virtual void mutate(int amt) = 0;

    /**
     * @brief Save internal changes to external data
     *
     */
    virtual void commit(void) = 0;

    /**
     * @brief Clear internal changes and load from external data
     *
     */
    virtual void abort(void) = 0;
};

#include <string>

using IntMenuData = MenuData<int>;
using StringMenuData = MenuData<std::string>;