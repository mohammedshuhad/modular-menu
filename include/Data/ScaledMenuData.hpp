#pragma once

#include "MenuData.hpp"

/**
 * @brief MenuData that can be scaled to an arbitrary (min, max)
 *
 * @tparam T the type of data to store
 */
template <typename T>
class ScaledMenuData : public MenuData<T> {
public:
    /**
     * @brief virtual destructor
     *
     */
    virtual ~ScaledMenuData() {}

    /**
     * @brief Returns the value scaled to the range [min, max]
     *
     * @param min the minimum valid value
     * @param max the maximum valid value
     * @return T the new value after scaling
     */
    virtual T scaled_value(T min, T max) = 0;
};

using ScaledIntMenuData = ScaledMenuData<int>;