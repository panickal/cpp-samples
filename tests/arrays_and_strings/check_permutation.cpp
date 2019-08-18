#include<iostream>
#include<string>
#include<gtest/gtest.h>

#define TESTNAME check_permutation

bool TESTNAME(std::string str){
    std::cout<<"Hello World";
    return false;
}

TEST(TESTNAME, tests) {
  EXPECT_EQ(TESTNAME("abcdefg"), true);
  EXPECT_EQ(TESTNAME("abcdecfg"), false);
}
