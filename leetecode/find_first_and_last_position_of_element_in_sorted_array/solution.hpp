// 34. Find First and Last Position of Element in Sorted Array
//
// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// Example 1:
//
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
//
// Example 2:
//
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
//
//
//
// Constraints:
//
//     0 <= nums.length <= 10^5
//     -10^9 <= nums[i] <= 10^9
//     nums is a non decreasing array.
//     -10^9 <= target <= 10^9





#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      std::vector<int> list_pos;
      list_pos.push_back(-1);
      list_pos.push_back(-1);
      bool flag_find=false;
      for(int i=0;i<nums.size();i++){
        if(nums[i] == target){
          if(flag_find == true){
            list_pos[1]=i;
          }
          else{
            list_pos[0]=i;
            list_pos[1]=i;
            flag_find=true;
          }
        }
        else if(nums[i] > target){
          break;
        }

      }
      return list_pos;

    }
};
