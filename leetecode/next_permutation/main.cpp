#include<iostream>
#include<string>
#include<vector>
#include"solution.hpp"
using namespace std;
int main(){


  Solution tmp;
  std::vector<int> nums;

  // nums.push_back(3);
  // nums.push_back(4);
  // nums.push_back(2);
  // nums.push_back(1);

  // nums.push_back(1);
  // nums.push_back(2);
  // nums.push_back(3);

  // nums.push_back(3);
  // nums.push_back(2);
  // nums.push_back(1);

  // nums.push_back(1);
  // nums.push_back(1);
  // nums.push_back(5);

  // nums.push_back(1);
  // nums.push_back(3);
  // nums.push_back(2);


  for (size_t i = 0; i < nums.size(); i++) {
    cout<<nums[i]<<" ";
  }
  cout<<endl;

  tmp.nextPermutation(nums);
  for (size_t i = 0; i < nums.size(); i++) {
    cout<<nums[i]<<" ";
  }
  cout<<endl;

  return 0;
}




// 执行结果：
// 解答错误
// 显示详情
// 输入:
// [1,3,2]
// 输出
// [3,2,1]
// 预期结果
// [2,1,3]
