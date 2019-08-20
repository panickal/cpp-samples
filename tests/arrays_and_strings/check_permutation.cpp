#include<iostream>
#include<string>
#include<vector>

#include<gtest/gtest.h>

bool check_permutation(const std::string &str1, const std::string &str2){
    if(str1.length() != str2.length()){
      return false;
    }
    
    std::vector<int> counts(128);
    for(auto &c : str1){
      counts[c] += 1;
    }

    for(auto &c : str2){
      counts[c] -= 1;
      if(counts[c] < 0){
        return false;
      }
    }

    return true;
}

TEST(check_permutation, tests) {
  EXPECT_EQ(check_permutation("abcdefg", "gcdfa"), false);
  EXPECT_EQ(check_permutation("abcdefg", "gcdefa"), false);
  EXPECT_EQ(check_permutation("abcdecfg", "asdasda"), false);
}
