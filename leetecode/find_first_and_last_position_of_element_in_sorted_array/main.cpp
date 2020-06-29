#include<iostream>
#include<string>
#include <vector>
#include"solution.hpp"
using namespace std;
int main(){
  Solution tmp;
  std::vector<int> v;
  v.push_back(5);
  v.push_back(7);
  v.push_back(7);
  v.push_back(8);
  v.push_back(8);
  v.push_back(10);


std::vector<int> ret=tmp.searchRange(v,6);
  cout<<"0: "<<ret[0]<<endl;
  cout<<"1: "<<ret[1]<<endl;

  return 0;
}
