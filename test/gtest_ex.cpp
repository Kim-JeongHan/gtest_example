#include "gtest/gtest.h"
#include "gtest_test/gtest_test.hpp"

TEST(FooTest, OutputsStringParameter) {
  testing::internal::CaptureStdout();  // Redirect stdout to a string
  foo("Hello, world!");
  std::string output = testing::internal::GetCapturedStdout();  // Get the redirected output
  EXPECT_EQ(output, "Hello, world!\n");
}