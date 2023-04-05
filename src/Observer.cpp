#include "Observer.h"

/*Observer::Observer(Subject& subject) : m_subject{subject} {
    m_subject.attach(this);
}*/

Observer::Observer(std::shared_ptr<ISubject> subject) : m_subject{subject} {
    m_subject->attach(this);
}

Observer::~Observer() {
    m_subject->detach(this);
}

void Observer::update(const std::vector<std::shared_ptr<Cell>>& board,
    const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns)
{
    
}
