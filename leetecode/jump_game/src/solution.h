#include <vector>
#include <iostream>
#include <vector>

using namespace std;

//55. Jump Game

//You are given an integer array nums. You are initially positioned at the  \\
//array's first index, and each element in the array represents your maximum  \\
//jump length at that position.

//Return true if you can reach the last index, or false otherwise.



//Example 1:

//Input: nums = [2,3,1,1,4]
//Output: true
//Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

//Example 2:

//Input: nums = [3,2,1,0,4]
//Output: false
//Explanation: You will always arrive at index 3 no matter what. Its maximum \\
//jump length is 0, which makes it impossible to reach the last index.



//Constraints:

//    1 <= nums.length <= 104
//    0 <= nums[i] <= 105
///0 set a list to save unavailable_list
/// set a list to save wait_list
///1 set last point as target ,
///2 get all previous point can reach target by one step
///3  if no previous points,then put the point to unavailable_list
///4  if previous points contains start_point
///5  if set one point as target_point ,then do (2),if one succeed,return succeed
///
class Solution {
public:


  bool reverseJump(vector<int>& nums,int pos,vector<bool> &dones)
  {
//    std::cout<<"nums:"<<std::endl;
//    for(auto it:nums)
//    {
//      std::cout<<" "<<it;
//    }
//    std::cout<<std::endl;

//    std::cout<<"dones:"<<std::endl;
//    for(auto it:dones)
//    {
//      std::cout<<" "<<it;
//    }
//    std::cout<<std::endl;


//    vector<int> l_pos_onestep;
    for(int i=0;i<pos;i++){
      if ((dones[i])==false && (pos-i<=nums[i]) ) {
//        l_pos_onestep.push_back(i);
        if (i== 0) {
          return true;
        }
        else{
          if (reverseJump(nums,i,dones)) {
            return true;
          }
        }
      }
    }
    return false;

//    std::cout<<"l_pos_onestep:"<<std::endl;
//    for(auto it:l_pos_onestep)
//    {
//      std::cout<<" "<<it;
//    }
//    std::cout<<std::endl;

//    if (l_pos_onestep.size()==0) {
//      dones[pos]=true;
//      return false;
//    }
//    else if(l_pos_onestep[0]==0){
//      return true;
//    }
//    else{
//      for (int i=0;i<l_pos_onestep.size();i++) {
//        if (reverseJump(nums,l_pos_onestep[i],dones)) {
//          return true;
//        }

//      }
//      return false;
//    }

//    return false;

  }

    bool canJump(vector<int>& nums) {
      vector<bool> dones(nums.size(),false);

//      for(auto it:dones)
//      {
//        std::cout<<""<<it<<std::endl;

//      }

      if (nums.size() == 1) {
        return true;
      }

      if (reverseJump(nums,nums.size()-1,dones)) {
        return true;
      }
      else{
        return false;
      }

    }

//    bool canPartJump(vector<int>& nums,int &start,int &end) {

//    }
};
