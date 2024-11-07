#include "Scroll/SimpleScrollResponse.hpp"

#include <assert.h>

const SimpleScrollResponse SimpleScrollResponse::oneScroll = SimpleScrollResponse({ { 1, 0 } });
const SimpleScrollResponse SimpleScrollResponse::fiftyScroll = SimpleScrollResponse({ { 50, 0 } });
const SimpleScrollResponse SimpleScrollResponse::oneFiveScroll = SimpleScrollResponse({ { 1, 25 }, { 5, 0 } });

// Scroll: 1 2 5 10 25 50 100
// Time: 200 100 50 25 12 5 1 0
const SimpleScrollResponse SimpleScrollResponse::tuned10Scroll = SimpleScrollResponse::oneScroll;
const SimpleScrollResponse SimpleScrollResponse::tuned100Scroll = SimpleScrollResponse({ { 1, 50 }, { 2, 25 }, { 5, 5 }, { 10, 1 }, { 25, 0 }});
const SimpleScrollResponse SimpleScrollResponse::tuned1000Scroll = SimpleScrollResponse({ { 1, 50 }, { 2, 25 }, { 5, 12 }, { 10, 5 }, { 25, 1 }, { 50, 0 } });
const SimpleScrollResponse SimpleScrollResponse::tuned10000Scroll = SimpleScrollResponse({ { 1, 100 }, { 2, 50 }, { 5, 25 }, { 25, 12 }, { 100, 5 }, { 200, 1 }, { 500, 0 } });
const SimpleScrollResponse SimpleScrollResponse::tuned100000Scroll = SimpleScrollResponse({ { 1, 200 }, { 5, 100 }, { 25, 50 }, { 100, 25 }, { 500, 12 }, { 1000, 5 }, { 2000, 1 }, { 5000, 0 } });

SimpleScrollResponse::SimpleScrollResponse(std::vector<std::pair<int, int>> responseData) :
    m_responseData(responseData) {

    for (size_t i = 0; i < m_responseData.size() - 1; i++) {
        assert(m_responseData[i].second > m_responseData[i + 1].second);
    }

    assert(m_responseData.back().second == 0);
}

int SimpleScrollResponse::getScroll(int timeSinceLastScroll) const {
    for (size_t i = 0; i < m_responseData.size(); i++) {
        if (timeSinceLastScroll >= m_responseData[i].second) {
            return m_responseData[i].first;
        }
    }
    return 0;
}