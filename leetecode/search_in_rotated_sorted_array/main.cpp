#include<iostream>
#include<string>
#include"solution.hpp"
using namespace std;
int main(){
  Solution tmp;
  std::vector<int> v;
  // v.push_back(4);
  // v.push_back(5);
  // v.push_back(6);
  // v.push_back(7);
  // v.push_back(0);
  // v.push_back(1);
  // v.push_back(2);

  v.push_back(1);
  v.push_back(3);


  cout<<"result:"<<tmp.search(v,1);
  return 0;
}
