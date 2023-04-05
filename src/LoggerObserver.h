#pragma once
#include "IObserver.h"
#include "ISubject.h"
#include "ILogger.h"

#include <memory>

class LoggerObserver : public IObserver {
public:
    LoggerObserver() = default;
    explicit LoggerObserver(std::shared_ptr<ISubject> subject);
    explicit LoggerObserver(std::shared_ptr<ISubject> subject,
    std::unique_ptr<ILogger> shipsLogger);
    virtual ~LoggerObserver();
    virtual void update(const std::vector<std::shared_ptr<Cell>>& board,
        const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns) override;
private:
    std::shared_ptr<ISubject> m_subject;
    std::unique_ptr<ILogger> m_shipsLogger;
};
