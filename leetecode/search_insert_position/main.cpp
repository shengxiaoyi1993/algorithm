#include<iostream>
#include"solution.hpp"
#include<string>
#include<vector>
using namespace std;
int main(){
  Solution tmp;
  vector<int> numlist={1,3,5,6};
  cout<<"result:"<<tmp.searchInsert(numlist,0);
  return 0;
}
