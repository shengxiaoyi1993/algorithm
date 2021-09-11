// 41. First Missing Positive
//
// Given an unsorted integer array, find the smallest missing positive integer.
//
// Example 1:
//
// Input: [1,2,0]
// Output: 3
//
// Example 2:
//
// Input: [3,4,-1,1]
// Output: 2
//
// Example 3:
//
// Input: [7,8,9,11,12]
// Output: 1
//
// Note:
//
// Your algorithm should run in O(n) time and uses constant extra space.
//

//循环，计算计算出最小值
//  使用map

#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:

    int firstMissingPositive(vector<int>& nums) {
        map<int ,int> tmpmap;
        size_t nums_size=nums.size();
        for (size_t i = 0; i < nums_size; i++) {
          if(nums_size>0){
            tmpmap[nums[i]]=1;
          }
        }
        int seq=1;
        while (true) {
          if(tmpmap[seq] == 0){
            return seq;
          }
          seq++;
        }
        return 0;
    }
};
