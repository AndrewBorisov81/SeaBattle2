#include "ViewObserver.h"

#include <iostream>

ViewObserver::ViewObserver(std::shared_ptr<ISubject> subject) 
    : m_subject{subject}
{
    m_subject->attach(this);
}

ViewObserver::ViewObserver(std::shared_ptr<ISubject> subject,
    std::shared_ptr<IView> view) 
    : m_subject{subject}, m_view{view}
{
    m_subject->attach(this);
}

ViewObserver::~ViewObserver() {
    m_subject->detach(this);
}

void ViewObserver::update(const std::vector<std::shared_ptr<Cell>>& board,
    const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns)
{
    if(m_view) {
        m_view->updateView(board, ships);
    }
    std::cout << "ViewObserver Update!" << '\n';
}
