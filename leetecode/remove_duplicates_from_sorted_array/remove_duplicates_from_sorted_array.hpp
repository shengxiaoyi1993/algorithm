#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if(nums.size()==0){
        return 0;
      }
      else{
        int pre=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
          if(pre==nums[i]){
          }
          else{
            nums[count]=nums[i];
            count++;
            pre=nums[i];
          }
        }
        return count;
      }
    }
};
