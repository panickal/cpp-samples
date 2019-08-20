#include<string>
#include<unordered_map>
#include<bitset>

#include<gtest/gtest.h>

bool palindrone_permutation_hashtable(const std::string &str){
    std::unordered_map<char, bool> table(128);
    for(auto &c : str){
        if(c == ' '){
            continue;
        }
        auto &it = table.find(toupper(c));
        if(it == table.end()){
            table[toupper(c)] = true;
        }
        else {
            it->second = !it->second;
        }
    }

    int count_of_ones = 0;
    for(auto &c : str){
        if(c == ' '){
            continue;
        }
        if(table[toupper(c)] == true){
            ++count_of_ones;
        }
    }

    if(count_of_ones <= 1){
        return true;
    }

    return false;
}

bool palindrone_permutation_bitvector(const std::string &str){
    std::bitset<26> bitvector(false);
    for(auto &c : str){
        if(isalpha(c)){
            bitvector.flip(toupper(c) - 'A');
        }
    }
    if(bitvector.count() <= 1){
        return true;
    }
    return false;
}

TEST(palindrone_permutation, tests) {
    EXPECT_EQ(palindrone_permutation_hashtable("tact coa"), true);
    EXPECT_EQ(palindrone_permutation_hashtable("abdnlf"), false);
    EXPECT_EQ(palindrone_permutation_hashtable("Rats live on no evil star"), true);
    
    EXPECT_EQ(palindrone_permutation_bitvector("tact coa"), true);
    EXPECT_EQ(palindrone_permutation_bitvector("abdnlf"), false);
    EXPECT_EQ(palindrone_permutation_bitvector("Rats live on no evil star"), true);
}