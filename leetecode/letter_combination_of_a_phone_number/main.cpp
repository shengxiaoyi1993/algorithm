#include<iostream>
#include<string>
#include<vector>
#include"solution.hpp"
using namespace std;
int main(){
  Solution tmp;
  vector<string> list=tmp.letterCombinations("23");
  for (size_t i = 0; i < list.size(); i++) {
    cout<<list[i]<<endl;
  }

  return 0;
}
