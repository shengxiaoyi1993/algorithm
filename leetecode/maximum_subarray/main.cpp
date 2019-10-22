#include<iostream>
#include<string>
#include<vector>
#include"solution.hpp"
using namespace std;
int main(){
  Solution tmp;
  vector<int> numlist = {-2,1,-3,4,-1,2,1,-5,4};
  cout<<"result: "<<tmp.maxSubArray(numlist);
  return 0;
}
