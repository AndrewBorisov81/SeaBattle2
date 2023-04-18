#include "LoggerObserver.h"
#include "ILogger.h"
#include "ISubject.h"
#include "ShipsLogger.h"
#include "ModelSubject.h"
#include "Cell.h"
#include "Ship.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>
#include <vector>

using ::testing::AtLeast;

class ICell {
public:
    virtual ~ICell(){};
    virtual int getRow() const = 0;
};

class IShip {
public:
    virtual ~IShip(){};
    virtual int getRow() const  = 0;
};

class MockCell: public ICell, public Cell {
public:
    virtual ~MockCell(){}
    int getRow() const override { return m_row; }
private:
    int m_row;
};

class MockShip: public IShip, public Ship {
public:
    virtual ~MockShip(){}
    int getRow() const override { return m_row; }
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
    MOCK_METHOD(void, attach, (IObserver*), (override));
    MOCK_METHOD(void, detach, (IObserver*), (override));
    MOCK_METHOD(void, notify, (const std::vector<std::shared_ptr<Cell>>& board,
        const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns), (override));
};

class TestLoggerObserver : public ::testing::Test {
public:
    void SetUp() override 
    {   
        //m_shipsLogger = std::make_unique<MockShipsLogger>();
       // m_modelSubject = std::make_unique<MockModelSubject>();
        //m_loggerObserver = std::make_unique<LoggerObserver>();
    }
    
    void TearDown() override 
    {

    }
protected:
    //std::unique_ptr<LoggerObserver> m_loggerObserver;
    //std::unique_ptr<MockShipsLogger> m_shipsLogger;
    //std::unique_ptr<MockModelSubject> m_modelSubject; 
};

TEST(TestLoggerObserverSimple, createTestLoggerObserver) {
    std::vector<std::shared_ptr<Cell>> cells;
    cells.push_back(std::make_shared<MockCell>());
    std::vector<std::shared_ptr<Ship>> ships;
    ships.push_back(std::make_shared<MockShip>());
    std::unique_ptr<ILogger> shipsLogger = std::make_unique<MockShipsLogger>();
    MockShipsLogger* mockShipsLogger = static_cast<MockShipsLogger*>(shipsLogger.get());
    EXPECT_CALL(*mockShipsLogger, update(cells, ships))                  
      .Times(AtLeast(1));
    std::shared_ptr<ISubject> modelSubject = std::make_shared<MockModelSubject>();
    MockModelSubject* mockModelSubject = static_cast<MockModelSubject*>(modelSubject.get());
    EXPECT_CALL(*mockModelSubject, notify(cells, ships, 10, 10))                  
      .Times(AtLeast(1));
    auto loggerObserver = std::make_unique<LoggerObserver>(modelSubject, std::move(shipsLogger));
}
