#pragma once

#include "Data/ActionMenuData.hpp"

#include <functional>

class SimpleActionMenuData : public ActionMenuData {
public:
    SimpleActionMenuData(std::string title, std::function<void(void)> action);

    virtual std::string key(void) override;
    virtual void action(void) override;

    void setTitle(std::string title);
private:
    std::string m_title;
    std::function<void(void)> m_action;
};