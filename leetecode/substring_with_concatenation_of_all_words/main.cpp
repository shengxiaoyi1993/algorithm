#include<iostream>
#include<string>
#include<vector>
#include"solution.hpp"
using namespace std;
int main(){
  Solution tmp;
  string s="a";
  std::vector<string> list;
  list.push_back("a");
  list.push_back("a");

  // list.push_back("good");
  // list.push_back("best");
  // list.push_back("word");

  std::vector<int> list_po = tmp.findSubstring(s,list);
  for (size_t i = 0; i < list_po.size(); i++) {
    std::cout << list_po[i] << '\n';
  }


  return 0;
}
