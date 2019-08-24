#include <string>

#include <gtest/gtest.h>

bool is_rotation(const std::string &str1, const std::string &str2) {
    if(str1.length() != str2.length()) {
        return false;
    }
    
    std::string s1s1 = str1 + str1;
    if (s1s1.find(str2) != std::string::npos) {
        return true;
    }
    
    return false;
}

TEST(is_rotation, tests) {
    EXPECT_EQ(is_rotation("waterbottle","erbottlewat"), true);
    EXPECT_EQ(is_rotation("watetle","erbottlewat"), false);
    EXPECT_EQ(is_rotation("watetlevsds","erbottlewat"), false);
    EXPECT_EQ(is_rotation("camelcase","casecamel"), true);
}