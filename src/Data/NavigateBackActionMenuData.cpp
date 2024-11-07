#include "Data/NavigateBackActionMenuData.hpp"

NavigateBackActionMenuData::NavigateBackActionMenuData(ViewManager &viewManager, std::string label) :
    m_viewManager(viewManager), m_label(label) {

}

std::string NavigateBackActionMenuData::key(void) {
    return m_label;
}

void NavigateBackActionMenuData::action(void) {
    m_viewManager.back();
}