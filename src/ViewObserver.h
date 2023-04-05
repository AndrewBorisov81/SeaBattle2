#pragma once
#include "IObserver.h"
#include "ISubject.h"
#include "IView.h"

class ViewObserver : public IObserver {
public:
    ViewObserver() = default;
    ViewObserver(std::shared_ptr<ISubject> subject);
    ViewObserver(std::shared_ptr<ISubject> subject,
        std::shared_ptr<IView> view);
    virtual ~ViewObserver();
    virtual void update(const std::vector<std::shared_ptr<Cell>>& board,
    const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns);
private:
    std::shared_ptr<ISubject> m_subject;
    std::shared_ptr<IView> m_view;
};
