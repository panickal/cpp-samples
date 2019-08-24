#include<string>

#include<gtest/gtest.h>

bool one_away(const std::string &str1, const std::string &str2){
    std::string larger_str = str1.length() >= str2.length() ? str1:str2;
    std::string smaller_str = str1.length() < str2.length() ? str1:str2;

    if(larger_str.length() - smaller_str.length() > 1){
        return false;
    }
    else if (larger_str.length() == smaller_str.length()){
        bool different = false;
        for(int i = 0; i < larger_str.length(); ++i){
            if(larger_str[i] != smaller_str[i]){
                if(different){
                    return false;
                }
                different = true;
            }
        }
        return true;
    }
    else{
        for(int li = 0, si = 0; li < larger_str.length() && si < smaller_str.length();){
            if(larger_str[li] != smaller_str[si]){
                if(li != si){
                    return false;
                }
                ++li;
            } else {
                ++li;
                ++si;
            }
        }
        return true;
    }
    return false;
}

TEST(one_away, tests) {
    EXPECT_EQ(one_away("pale", "ple"), true);
    EXPECT_EQ(one_away("pales", "pale"), true);
    EXPECT_EQ(one_away("psale", "pale"), true);
    EXPECT_EQ(one_away("pale", "bale"), true);
    EXPECT_EQ(one_away("pale", "bae"), false);
    EXPECT_EQ(one_away("ppbb", "bbpp"), false);
}