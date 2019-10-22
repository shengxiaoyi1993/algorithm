#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      if(nums.size()==0){
        return 0;
      }
      else{
        int count=0;
        for(int i=0;i<nums.size();i++){
          if(nums[i]==val){
          }
          else{
            nums[count]=nums[i];
            count++;
          }
          }
          return count;
      }

    }
};
