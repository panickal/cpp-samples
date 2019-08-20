#include<string>

#include<gtest/gtest.h>

std::string urlify(const std::string &str, const int &str_len){
    std::string tmp_str = str;
    
    int num_spaces = 0;
    for(int i=0; i<str_len; ++i){
        if(isspace(str[i])){
            ++num_spaces;
        }
    }

    int length = num_spaces * 3 + str_len - num_spaces;
    for(int i = str_len-1; i >= 0; --i){
        char c = tmp_str[i];
        if(isspace(c)){
            tmp_str[--length] = '0';
            tmp_str[--length] = '2';
            tmp_str[--length] = '%';
        } else {
            tmp_str[--length] = c;
        }
    }

    return tmp_str;
}

TEST(urlify, tests) {
    EXPECT_EQ(urlify("Mr John Smith    ", 13), "Mr%20John%20Smith");
    EXPECT_EQ(urlify("Mr  John  Smith        ", 15), "Mr%20%20John%20%20Smith");
    EXPECT_EQ(urlify("MrJohnSmith", 11), "MrJohnSmith");
}