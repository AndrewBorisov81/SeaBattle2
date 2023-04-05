#include "Subject.h"
#include "IObserver.h"

Subject::Subject() {

}

Subject::~Subject() {

}

void Subject::attach(IObserver* observer) {
    m_observers.push_front(observer);
}

void Subject::detach(IObserver* observer) {
   m_observers.remove(observer);
}

void Subject::notify(const std::vector<std::shared_ptr<Cell>>& board,
    const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns) {
    for (auto& o: m_observers) {
        o->update(board, ships, rows, columns);
    }
}
