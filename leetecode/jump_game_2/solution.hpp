#include <iostream>
using namespace std;


// 45. Jump Game II
//
// Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
// Each element in the array represents your maximum jump length at that position.
//
// Your goal is to reach the last index in the minimum number of jumps.
//
// Example:
//
// Input: [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2.
//     Jump 1 step from index 0 to 1, then 3 steps to the last index.
//
// Note:
//
// You can assume that you can always reach the last index.

//path[] nums[]
//测试迭代法
//假设前面的字符串已经得到最短的路径
//  若前面的字符串路径path[0]!= nums[0],path[0]+=1
//  若前面的字符串路径 path[0]== nums[0],
//     若newnum>path[0],path[0]=path[0]+1
//     若newnum<=path[0],path.insert(path.begin(),1)

//faq
//需要验证按照以上方法得到的路径始终最短
//每个点加上最大跳跃距离，其所能达到的位置是固定的
//





//从第一点开始跳，得到一个落点范围
//从落点范围中的每个点开始跳，得到跳跃到的最远距离（从而确定了一次跳跃），又得到一个范围，重新计算
//直到落点大于等于中点

class Solution {
public:
    int jump(vector<int>& nums) {
      int ret=0;
      int start=0;
      int end=1;
      int numsize=nums.size();
      while (end<numsize) {
        int tmpmax=start;
        for (size_t i = start; i < end; i++) {
          tmpmax=tmpmax>(i+nums[i])?tmpmax:(i+nums[i]);
        }
        ret++;
        start=end;
        end=tmpmax+1;
      }
      return ret;
    }
};
