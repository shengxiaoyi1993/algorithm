#include <vector>
#include <iostream>
#include <vector>

using namespace std;

//81. Search in Rotated Sorted Array II

//There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

//Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length)
//such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
//For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

//Given the array nums after the rotation and an integer target,
//return true if target is in nums, or false if it is not in nums.

//You must decrease the overall operation steps as much as possible.



//Example 1:

//Input: nums = [2,5,6,0,0,1,2], target = 0
//Output: true

//Example 2:

//Input: nums = [2,5,6,0,0,1,2], target = 3
//Output: false



//Constraints:

//    1 <= nums.length <= 5000
//    -104 <= nums[i] <= 104
//    nums is guaranteed to be rotated at some pivot.
//    -104 <= target <= 104







/// 二分法搜索
/// 比较中值 起点 末点，target的大小关系
/// > 起点>=末点 处于回环状态 使用二分法
/// > 起点<末点 处于有序状态 使用普通二分法

/// 中值 起点
/// 起点>=中值
///
/// 起点< 中值

class Solution {
public:
  /// 二分法搜索，分隔的区域 一部分是有序的，一部分是原有的规则
  /// 分别与nums[0]与nums[size/2]比较target
  ///
  /// 二分法搜索，看成一个环，环的表征(start,end),若end<start,则越过断层
  /// 每次搜索都将ring分隔为原来的一半
  bool search(vector<int>& nums, int target) {

    return searchInRing(nums,0,nums.size()-1,target);

  }



  bool searchInRing(vector<int>& nums,int start,int end, int target)
  {

//    std::cout<<"start:"<<start
//               <<" end:"<<end
//            <<endl;

    int length=end-start+1;
    if (length == 0) {
      return false;
    }
    else if (length == 1) {
      return nums[start]==target;
    }

    else if (length == 2) {
      return nums[start]==target || nums[end]==target;
    }
    else{
      int mid=(start+end)/2;
      if (nums[start]<nums[mid]) {

        if (target<=nums[mid]&& target>=nums[start]) {
          return searchInRing(nums,start,mid,target);
        }
        else{
          return searchInRing(nums,mid,end,target);
        }

      }
      else if(nums[end]>nums[mid]){

        if (target>=nums[mid]&& target<=nums[end]) {
          return searchInRing(nums,mid,end,target);
        }
        else{
          return searchInRing(nums,start,mid,target);
        }

      }
      else{
        return searchInRing(nums,start,mid,target)||searchInRing(nums,mid,end,target);
      }

    }





  }

};
