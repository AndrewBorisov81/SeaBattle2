#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::AtLeast;

class MyClass {
public:
  MyClass(int value) : value_(value) {}
  int GetValue() const { return value_; }
private:
  int value_;
};

class MyTestFixture : public testing::Test {
protected:
  virtual void SetUp() {
    // SetUp code goes here
    my_class_ = new MyClass(42);
  }

  virtual void TearDown() {
    // TearDown code goes here
    delete my_class_;
  }

  // Any variables you declare here can be accessed
  // by all tests in the fixture.
  MyClass* my_class_;
};

TEST_F(MyTestFixture, Test1) {
  EXPECT_EQ(my_class_->GetValue(), 42);
}

TEST_F(MyTestFixture, Test2) {
  my_class_->GetValue(); // This will fail the test.
  FAIL() << "Test not implemented yet";
}

TEST(MyTestSimple, Test3) {
  MyClass myClass(10);
  EXPECT_EQ(myClass.GetValue(), 10);
}

TEST(SkipTest, DoesSkip) {
  GTEST_SKIP() << "Skipping single test";
  EXPECT_EQ(0, 1);  // Won't fail; it won't be executed
}
