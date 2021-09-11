#include<iostream>
#include<string>
#include <algorithm>
#include"solution.hpp"
using namespace std;
int main(){
  Solution tmp;
int vals[]={0,1,0,2,1,0,1,3,2,1,2,1};
int size_vals=12;
vector<int> candidates;
for (size_t i = 0; i < size_vals; i++) {
  candidates.push_back(vals[i]);
}

std::cout << "result:" <<tmp.trap(candidates)<< '\n';
  return 0;
}
