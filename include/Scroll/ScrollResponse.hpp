#pragma once

/**
 * @brief Interface to alter scroll amounts based on how fast the scrolling is done
 *
 */
class ScrollResponse {
public:
    virtual ~ScrollResponse() {}

    virtual int getScroll(int timeSinceLastScroll) const = 0;
};