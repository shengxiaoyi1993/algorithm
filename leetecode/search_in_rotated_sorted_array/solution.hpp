#include <iostream>
#include <vector>
using namespace std;

// Suppose an array sorted in ascending(升) order is rotated at some pivot（支点） unknown to you beforehand.
//
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
// You are given a target value to search. If found in the array return its index, otherwise return -1.
//
// You may assume no duplicate（ 复写） exists in the array.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// Example 1:
//
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
//
// Example 2:
//
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1


//二分法，但是不知道支点
//思路每次计算，去除一般的数据量
//每次取中值mid=[(start+end)/2] 初始 ：start =0 end=size-1,表示结果落在的范围，注意是start->end start<=end
//  若target>nums[mid],需要确定分布，（[mid]>[start],则左边是单调递增；[mid]<[end],则右边为单调;[mid]==[start],仅有两个数）
//    若[mid]>=[start]，比较target与[start]，则start=mid+1
//    若[mid]<[start]，比较target与nums[start]
//      若target>nums[start]，则end=mid-1
//      否则start=mid+1
//  若target<nums[mid],比较target与nums[start]
//    若[mid]>=[start],比较target与nums[start]
//      若target<nums[start],start=mid+1
//      否则end=mid-1
//    若[mid]<[start]，比较target与[start]，则end=mid-1
//循环该过程，直至结束

class Solution {
public:
    int search(vector<int>& nums, int target) {
      int v_start=0;
      int v_end=nums.size()-1;
      while(v_start<v_end){
        // cout<<"head v_start: "<<v_start<<"v_end: "<<v_end<<endl;
        int v_mid=(v_start+v_end)/2;
        if(target>nums[v_mid]){
          if(nums[v_mid]>=nums[v_start]){
            v_start=v_mid+1;
          }
          else{
            if(target>nums[v_start]){
              v_end=v_mid-1;
            }
            else if(target<nums[v_start]){
              v_start=v_mid+1;
            }
            else {
              return v_start;
            }
          }
        }
        else if(target<nums[v_mid]){
          if(nums[v_mid]>=nums[v_start]){
            if(target<nums[v_start]){
              v_start=v_mid+1;
            }
            else if(target>nums[v_start]){
              v_end=v_mid-1;
            }
            else {
              return v_start;
            }
          }
          else{
            v_end=v_mid-1;
          }
        }
        else{
          return v_mid;
        }

        // cout<<"tail v_start: "<<v_start<<"v_end: "<<v_end<<endl;

      }
      if(v_start == v_end  && target == nums[v_start]){
        return v_start;
      }
      else{
        return -1;
      }

    }
};
