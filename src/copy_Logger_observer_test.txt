#include "LoggerObserver.h"
#include "ILogger.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>
#include <vector>

class Cell {
public:
    virtual ~Cell(){}
    int getRow() const { return m_row; }
private:
    int m_row;
};

class Ship {
public:
    virtual ~Ship(){}
    int getRow() const { return m_row; }
private:
    int m_row;
};

class MockShipsLogger: public ILogger {
public:
  MOCK_METHOD(void, update, (const std::vector<std::shared_ptr<Cell>>& board,
    const std::vector<std::shared_ptr<Ship>>& ships), (override));
};

class MockModelSubject: public ISubject {
public:
  //virtual void attach(IObserver* observer) = 0;
    /*virtual void detach(IObserver* observer) = 0;
    virtual void notify(const std::vector<std::shared_ptr<Cell>>& board,
        const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns) = 0;*/
    MOCK_METHOD(void, attach, (IObserver*), (override));
};

class TestLoggerObserver : public ::testing::Test {
public:
    void SetUp() override 
    {   
        m_shipsLogger = std::make_unique<MockShipsLogger>();
       // m_modelSubject = std::make_unique<MockModelSubject>();
        m_loggerObserver = std::make_unique<LoggerObserver>();
    }
    
    void TearDown() override 
    {

    }
protected:
    std::unique_ptr<LoggerObserver> m_loggerObserver;
    std::unique_ptr<MockShipsLogger> m_shipsLogger;
    std::unique_ptr<MockModelSubject> m_modelSubject; 
};

TEST_F(TestLoggerObserver, createTestLoggerObserver) {

}
