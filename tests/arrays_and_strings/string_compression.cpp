#include<string>

#include<gtest/gtest.h>

std::string string_compression(const std::string &str){
    if(str.empty()){
        return false;
    }
    std::string o_str;
    o_str.reserve(str.length());
    int counter = 1;
    char current_char = str[0];

    for(int i=1; i<str.length(); ++i){
        if(current_char == str[i]){
            ++counter;
        }
        if(current_char != str[i] || i == str.length()-1){
            o_str += current_char;
            o_str += std::to_string(counter);
            current_char = str[i];
            counter = 1;
        }
        if(o_str.length() > str.length()){
            return str;
        }
    }
    return o_str;
}

TEST(string_compression, tests) {
    EXPECT_EQ(string_compression("aabcccccaaa"), "a2b1c5a3");
}