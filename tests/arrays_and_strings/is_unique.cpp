#include<iostream>
#include<string>
#include<gtest/gtest.h>

#define TESTNAME is_unique

bool TESTNAME(std::string str){
    std::cout<<"Hello World";
    return false;
}

TEST(TESTNAME, Tests) {
  EXPECT_EQ(TESTNAME("abcdefg"), true);
  EXPECT_EQ(TESTNAME("abcdecfg"), false);
}
