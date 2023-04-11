#pragma once
#include "Subject.h"
#include "Model.h"

class Cell;
class Ship;
class IObserver;

class ModelSubject : public Subject {
public:
    ModelSubject();
    virtual ~ModelSubject();
    void attach(IObserver* observer) override;
    void detach(IObserver* observer) override;
    void notify(const std::vector<std::shared_ptr<Cell>>& board,
    const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns) override;
private:
    std::forward_list<IObserver*> m_observers;
};
