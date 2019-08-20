//
// CTCI
// TEST FIXTURE
// clang-tidy
// coverity
// clang-format

#include<iostream>
#include<string>
#include<bitset>
#include<unordered_map>
#include<algorithm>

#include<gtest/gtest.h>

bool is_unique_hashmap(const std::string &str){
    std::unordered_map<char, bool> table;
    for(auto &c : str){
      if(table.count(c) != 0){
        return false;
      }
      table[c] = true;
    }
    return true;
}

bool is_unique_bitvector(const std::string &str){
  std::bitset<256> bits(false);
  for(auto &c : str){
      if(bits.test(c)){
        return false;
      }
      bits.set(c, true);
    }
    return true;
}

bool is_unique_sort(const std::string &str){
  std::string tmp = str;
  std::sort(tmp.begin(), tmp.end());
  for(auto i=1; i<tmp.length(); i++){
      if(tmp[i-1] == tmp[i]){
        return false;
      }
    }
    return true;
}

using namespace std;

TEST(is_unique, tests) {
#ifdef CPP_DEBUG
  	vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
    for (auto word : words)
    {
        cout << word << string(": ") << boolalpha << is_unique_hashmap(word) <<endl;
    }
    cout <<endl << "Using bit vector" <<endl;
    for (auto word : words)
    {
        cout << word << string(": ") << boolalpha << is_unique_bitvector(word) <<endl;
    }
    cout <<endl << "Using no data structures" <<endl;
    for (auto word : words)
    {
        cout << word << string(": ") << boolalpha << is_unique_sort(word) <<endl;
    }
#endif
    EXPECT_EQ(is_unique_hashmap("abcde"), true);
    EXPECT_EQ(is_unique_hashmap("hello"), false);
    EXPECT_EQ(is_unique_hashmap("kite"), true);

    EXPECT_EQ(is_unique_bitvector("abcde"), true);
    EXPECT_EQ(is_unique_bitvector("hello"), false);
    EXPECT_EQ(is_unique_bitvector("kite"), true);

    EXPECT_EQ(is_unique_sort("abcde"), true);
    EXPECT_EQ(is_unique_sort("hello"), false);
    EXPECT_EQ(is_unique_sort("kite"), true);
}
