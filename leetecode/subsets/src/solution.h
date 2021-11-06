#include <vector>
#include <iostream>
#include <vector>

using namespace std;

//78. Subsets

//Given an integer array nums of unique elements, return all possible subsets (the power set).

//The solution set must not contain duplicate subsets. Return the solution in any order.



//Example 1:

//Input: nums = [1,2,3]
//Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

//Example 2:

//Input: nums = [0]
//Output: [[],[0]]



//Constraints:

//    1 <= nums.length <= 10
//    -10 <= nums[i] <= 10
//    All the numbers of nums are unique.


/// 迭代法
/// 每次增加一个数，所得数字为之前的结果加上之前的结果各加该数字组成的数组
/// 具体的方法为遍历

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

      vector<vector<int>> arr={{}};
      for (auto it:nums) {
        int size=arr.size();
        for (size_t i=0;i<size;i++) {
          auto list=arr[i];
          list.push_back(it);
          arr.push_back(list);
        }
      }
      return arr;
    }
};
