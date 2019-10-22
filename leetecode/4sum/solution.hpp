#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      int length=nums.size();
      vector<vector<int>> lis_res;
      sort(nums.begin(), nums.end());
      int flag_aleady=0;
      for(int i=length-1;i>=3;i--){
          vector<int> list_tmp(nums.begin(), nums.end()-(length-i));
          vector<vector<int>> list_res_3sum=threeSum(list_tmp,target-nums[i]);
          for(int j=0;j<list_res_3sum.size();j++){
            list_res_3sum[j].push_back(nums[i]);
            // if(list_res_3sum[j]!=*(lis_res.end()-1))
            int flag_alldiff=1;

            if(flag_aleady==1){
              // vector<vector<int>>::iterator item=lis_res.end()-1;
              for (vector<vector<int>>::iterator item = lis_res.begin(); item != lis_res.end(); item++) {
                cout<<endl;
                /* code */
                int flag_same=1;
                for (size_t m = 0; m < (*item).size(); m++) {
                  cout<<(*item)[m]<<" ";
                  /* code */
                  if((*item)[m]==list_res_3sum[j][m]){

                  }
                  else{
                    flag_same=0;
                    break;
                  }
                }

                if(flag_same==0){
                  flag_alldiff=1;
                }
                else{
                  flag_alldiff=0;
                  break;
                }
              }

            }
            if(flag_alldiff==0){
              continue;
            }
            lis_res.push_back(list_res_3sum[j]);
            flag_aleady=1;
          }
      }
      return lis_res;

    }
    vector<vector<int>> threeSum(vector<int>& nums,int target) {
      int size=nums.size();
      vector<vector<int>> res;
      if(size<=2){
        return res;
      }

      int ceil=size-2;
      for(int i=0;i<ceil;i++){
        if(i>0&&nums[i]==nums[i-1]){continue;}
        int left=i+1;
        int right=size-1;
        while(left<right){
          int sum=nums[i]+nums[left]+nums[right];
          if(sum>target){
            right--;
          }
          else if(sum<target){
            left++;
          }
          else{
            res.push_back({nums[i],nums[left++],nums[right--]});
            while(nums[right]==nums[right+1]&&left<right)right--;
            while(nums[left]==nums[left-1]&&left<right)left++;
          }

        }
        // i++;
        // while (i<size-2&&nums[i]==nums[i-1]) {
        //   i++;
        // }
      }
      return res;

    }
};
