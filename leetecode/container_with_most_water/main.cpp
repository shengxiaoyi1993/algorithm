#include<iostream>
#include<string>
#include<vector>
#include"solution.hpp"
using namespace std;
int main(){
  Solution tmp;
  vector<int> list={1,8,6,2,5,4,8,3,7};
  cout<<tmp.maxArea(list);
  return 0;
}
