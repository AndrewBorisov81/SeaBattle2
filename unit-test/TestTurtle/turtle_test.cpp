#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::AtLeast; 

class ITurtle {
public:
  virtual ~ITurtle() {}
  virtual void PenDown() = 0;
};

class Turtle: public ITurtle {
public:
    virtual ~Turtle(){}
    virtual void PenDown() override {};
};

class Painter {
public:
    Painter(){}
    virtual ~Painter(){}
    Painter(Turtle* turtle) : m_turtle{turtle}{}
    bool DrawCircle() 
    { 
      m_turtle->PenDown();
      return true; 
    };
private:
    Turtle* m_turtle;
};

class MockTurtle : public Turtle {
 public:
      virtual ~MockTurtle(){}
      MOCK_METHOD(void, PenDown, (), (override));
};

TEST(PainterTest, CanDrawSomething) {
  MockTurtle turtle;                             
  EXPECT_CALL(turtle, PenDown())              
      .Times(AtLeast(1));

  Painter painter(&turtle);                       

  EXPECT_TRUE(painter.DrawCircle());      
}
