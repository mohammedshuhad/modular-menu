#pragma once

#include "ScrollResponse.hpp"
#include <vector>

/**
 * @brief ScrollResponse that uses a lookup table to determine the scroll response
 *
 */
class SimpleScrollResponse : public ScrollResponse {
public:
    /**
     * @param responseData vector<pair> that holds the data to determine the scroll response
     * pair.first: How many units to move by. The smallest is 1
     * pair.second: Minimum number of millis since the last scroll event
     *
     * All pair.second's must be in decreasing order,
     * The last pair.second must equal 0
     *
     * @example responseData = {{1, 100}, {5, 50}, {10, 0}};
     * Move by 1 if it's been time>100ms since the last scroll event
     * Move by 5 if it's been 100>time>50ms since the last scroll event
     * Move by 10 if it's been at least 50ms>time>0ms since the last scroll event
     * */
    SimpleScrollResponse(std::vector<std::pair<int, int>> responseData);

    /**
     * @brief Returns how many units to move by given the time since the last scroll event
     *
     * @param timeSinceLastScroll Time since last scroll event measured in millis. Ex 100
     * @return number of units to skip by as determined by the response
     */
    virtual int getScroll(int timeSinceLastScroll) const override;

    static const SimpleScrollResponse oneScroll;
    static const SimpleScrollResponse fiftyScroll;
    static const SimpleScrollResponse oneFiveScroll;

    static const SimpleScrollResponse tuned10Scroll;
    static const SimpleScrollResponse tuned100Scroll;
    static const SimpleScrollResponse tuned1000Scroll;
    static const SimpleScrollResponse tuned10000Scroll;
    static const SimpleScrollResponse tuned100000Scroll;
protected:
    std::vector<std::pair<int, int>> m_responseData;
};