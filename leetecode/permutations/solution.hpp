#include <iostream>
using namespace std;

// 46. Permutations
//
// Given a collection of distinct integers, return all possible permutations.
//
// Example:
//
// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]


//迭代法
//动态规划

//计算前几个数的排列
//

class Solution {
public:

    vector<vector<int> > permute(vector<int>& nums) {
      // std::cout << "size:"<<nums.size() << '\n';
      vector<vector<int> > ret;
      if(nums.size()==0){
        return ret;
      }
      else if(nums.size() == 1){
        ret.push_back(nums);
      }
      else{
        vector<int> tmp(nums.begin(), nums.end()-1);
        vector<vector<int> > tmpret=permute(tmp);
        for (size_t i = 0; i < tmpret.size(); i++) {
          for (size_t j = 0; j <= tmpret[i].size(); j++) {
            tmpret[i].insert(tmpret[i].begin()+j,nums[nums.size()-1]);
            ret.push_back(tmpret[i]);
            tmpret[i].erase(tmpret[i].begin()+j);
          }
        }
      }
      return ret;

    }
};
