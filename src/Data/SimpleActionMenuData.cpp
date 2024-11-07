#include "Data/SimpleActionMenuData.hpp"

SimpleActionMenuData::SimpleActionMenuData(std::string title, std::function<void(void)> action) :
    m_title(title), m_action(action) {

}

std::string SimpleActionMenuData::key(void) {
    return m_title;
}

void SimpleActionMenuData::action(void) {
    m_action();
}

void SimpleActionMenuData::setTitle(std::string title) {
    m_title = title;
}