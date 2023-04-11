#include "LoggerObserver.h"
#include "ILogger.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <memory>

class MockShipsLogger: public ILogger {
public:
};

class MockModelSubject: public ISubject {
public:
};

class TestLoggerObserver : public ::testing::Test {
public:
    void SetUp() override 
    {
        //m_loggerObserver = std::make_unique<LoggerObserver>();
    }
    
    void TearDown() override 
    {

    }
protected:
    std::unique_ptr<ILogger> m_loggerObserver;
};
