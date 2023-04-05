#include "ModelSubject.h"
#include "IObserver.h"

ModelSubject::ModelSubject() {

}

ModelSubject::~ModelSubject() {

}

void ModelSubject::attach(IObserver* observer) {
    m_observers.push_front(observer);
}

void ModelSubject::detach(IObserver* observer) {
   m_observers.remove(observer);
}

void ModelSubject::notify(const std::vector<std::shared_ptr<Cell>>& board,
    const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns) {
    for (auto& o: m_observers) {
        o->update(board, ships, rows, columns);
    }
}
