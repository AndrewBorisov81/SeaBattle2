#include "ControllerObserver.h"

#include <memory>
#include <iostream>

ControllerObserver::ControllerObserver(std::shared_ptr<ISubject> subject)
    : m_subject{subject} 
{
    m_subject->attach(this);
}

ControllerObserver::~ControllerObserver() {
    m_subject->detach(this);
}

void ControllerObserver::update(const std::vector<std::shared_ptr<Cell>>& board,
    const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns)
{
    std::cout << "ControllerObserver Update!" << '\n';
}
