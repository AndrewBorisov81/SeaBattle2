#include "LoggerObserver.h"

#include <iostream>

 LoggerObserver::LoggerObserver(std::shared_ptr<ISubject> subject) 
     : m_subject{subject}
 {
    m_subject->attach(this);
 }

 LoggerObserver::LoggerObserver(std::shared_ptr<ISubject> subject,
    std::unique_ptr<ILogger> shipsLogger) 
    : m_subject{subject},
      m_shipsLogger{std::move(shipsLogger)}
{
    m_subject->attach(this);
}

 LoggerObserver::~LoggerObserver() {
    m_subject->detach(this);
 }

void LoggerObserver::update(const std::vector<std::shared_ptr<Cell>>& board,
        const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns)
{
    m_shipsLogger->update(board, ships);
    std::cout << "LoggerObserver Update!" << '\n';
}
