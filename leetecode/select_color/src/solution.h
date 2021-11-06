#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



//75. Sort Colors

//Given an array nums with n objects colored red, white, or blue, sort them in-place
//so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

//We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

//You must solve this problem without using the library's sort function.



//Example 1:

//Input: nums = [2,0,2,1,1,0]
//Output: [0,0,1,1,2,2]

//Example 2:

//Input: nums = [2,0,1]
//Output: [0,1,2]

//Example 3:

//Input: nums = [0]
//Output: [0]

//Example 4:

//Input: nums = [1]
//Output: [1]



//Constraints:

//    n == nums.length
//    1 <= n <= 300
//    nums[i] is 0, 1, or 2.



//Follow up: Could you come up with a one-pass algorithm using only constant extra space?



class Solution {
public:

  void sortColors(vector<int>& nums) {
    std::sort(nums.begin(),nums.end());

  }

//    void sortColors(vector<int>& nums) {
//      int num_0=0;
//      int num_1=0;
//      int num_2=0;
//      for (auto it:nums) {
//        switch (it) {
//          case 0:{
//            num_0++;
//            break;
//          }
//            case 1:{
//            num_1++;
//            break;

//          }
//          case 2:{
//            num_2++;
//            break;
//          }
//        }
//      }

//      int count=0;
//      for (int i=0;i<num_0;i++) {
//        nums[count]=0;
//        count++;
//      }
//      for (int i=0;i<num_1;i++) {
//        nums[count]=1;
//        count++;
//      }
//      for (int i=0;i<num_2;i++) {
//        nums[count]=2;
//        count++;
//      }
//    }
};
