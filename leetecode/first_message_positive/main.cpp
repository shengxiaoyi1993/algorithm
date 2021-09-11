#include<iostream>
#include<string>
#include <map>
#include <vector>
#include"solution.hpp"
using namespace std;

void testmap(){
  map<int ,int> tmpmap;
  tmpmap[0]=9;
  tmpmap[4]=9;
  cout<<"tmpmap[0]:"<<tmpmap[0]<<endl;
  // cout<<"tmpmap[2]:"<<tmpmap[2]<<endl;

}

int main(){
  std::vector<int> nums;
  int v[]={7,8,9,11,12};
  int size_v=5;

  for (size_t i = 0; i < size_v; i++) {
    nums.push_back(v[i]);
  }

  Solution tmp;

  cout<<"result:"<<tmp.firstMissingPositive(nums);
  return 0;
}
