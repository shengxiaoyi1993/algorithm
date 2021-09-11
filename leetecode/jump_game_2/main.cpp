#include<iostream>
#include<string>
#include <vector>
#include"solution.hpp"
using namespace std;
int main(){
  Solution tmp;
  vector<int> nums;
  #define LENGTHY 5
  int anums[LENGTHY]={2,3,1,1,4};
  for (size_t i = 0; i < LENGTHY; i++) {
    nums.push_back(anums[i]);

  }
  cout<<"result:"<<tmp.jump(nums)<<endl;
  return 0;
}
