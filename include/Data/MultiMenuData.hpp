#pragma once

#include "MenuData.hpp"

/**
 * @brief MenuData to hold multiple elements that can be scrolled through
 *
 * @tparam T
 */
template <typename T>
class MultiMenuData : public MenuData<T> {
public:
    /**
     * @brief virtual destructor
     *
     */
    virtual ~MultiMenuData() {}

    /**
     * @brief Returns the number of elements in the data
     *
     * @return int the number of elements in the data
     */
    virtual int size(void) = 0;

    /**
     * @brief Returns the index of the current element
     *
     * @return int the index of the current element
     */
    virtual int index(void) = 0;

    /**
     * @brief Returns the value at the index
     *
     * @param index the index to get the value from
     * @return T the value at the index
     */
    virtual T value_at(int index) = 0;

    /**
     * @brief Scrolls to the next element in the multi-data and return whether or not
     *        the new current element is the first element
     *
     * @return true new current element is the first element
     * @return false new current element is not the first element
     */
    virtual bool next(void) = 0;
};

using CharMultiMenuData = MultiMenuData<char>;