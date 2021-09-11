#include<iostream>
#include<string>
#include <vector>
#include"solution.hpp"
using namespace std;
int main(){
  Solution tmp;
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);

  vector<vector<int> > lists=tmp.permute(nums);

  cout<<"result:"<<endl;
  for (size_t i = 0; i < lists.size(); i++) {
    for (size_t j = 0; j < lists[i].size(); j++) {
      std::cout << lists[i][j] << ' ';
    }
    std::cout   << '\n';
  }
  std::cout   << '\n';


  return 0;
}
