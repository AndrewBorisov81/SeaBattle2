#pragma once
#include "IObserver.h"
#include "Subject.h"

#include <memory>

class Observer : public IObserver {
public:
    //Observer(Subject& subject);
    Observer() = default;
    explicit Observer(std::shared_ptr<ISubject> subject);
    virtual ~Observer();
    virtual void update(const std::vector<std::shared_ptr<Cell>>& board,
    const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns) override;
protected:
    std::shared_ptr<ISubject> m_subject;

private:
    //Subject& m_subject;
    static int m_number;
};
