//#include "LoggerObserver.h"
//#include "ILogger.h"

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

/*class MockShipsLogger: public ILogger {
public:
  MOCK_METHOD(void, update, (const std::vector<std::shared_ptr<Cell>>& board,
    const std::vector<std::shared_ptr<Ship>>& ships), (override));
};*/

/*class MockModelSubject: public ISubject {
public:
    MOCK_METHOD(void, attach, (IObserver*), (override));
    MOCK_METHOD(void, detach, (IObserver*), (override));
    MOCK_METHOD(void, update, (const std::vector<std::shared_ptr<Cell>>& board,
        const std::vector<std::shared_ptr<Ship>>& ships, int rowd, int columns), (override));
};*/

class TestLoggerObserver : public ::testing::Test {
public:
    void SetUp() override 
    {   
        //m_shipsLogger = std::make_unique<MockShipsLogger>();
        //m_modelSubject = std::make_unique<MockModelSubject>();
        /*m_loggerObserver = std::make_unique<LoggerObserver>();*/
    }
    
    void TearDown() override 
    {

    }
protected:
    //std::unique_ptr<LoggerObserver> m_loggerObserver;
    //std::unique_ptr<MockShipsLogger> m_shipsLogger;
    //std::unique_ptr<MockModelSubject> m_modelSubject; 
};

TEST_F(TestLoggerObserver, createTestLoggerObserver) {

}
