#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      if(nums.size()<1)
    return 0;

int res = nums[0];
for(int i=1;i<nums.size();i++){
    if(nums[i]<nums[i]+nums[i-1]){
        nums[i] = nums[i]+nums[i-1];
    }

    if(nums[i]>res)
        res = nums[i];
}

return res;
      // int sum_left=0;
      // int max_sum_left=0;
      // int left_num=0;
      // int sum_right=0;
      // int max_sum_right=0;
      // int size=nums.size();
      // int right_num=size-1;
      // cout<<"size:"<<size<<endl;
      // for(int i=0;i<size;i++){
      //   sum_left+=nums[i];
      //   if(max_sum_left>sum_left){
      //     max_sum_left=sum_left;
      //     left_num=i;
      //   }
      //
      //   sum_right+=nums[size-i-1];
      //   if(max_sum_right>sum_right){
      //     max_sum_right=sum_right;
      //     right_num=size-i-1;
      //   }
      // }
      // cout<<"num_left:"<<left_num<<endl;
      // cout<<"num_right"<<right_num<<endl;
      // int max_sum=0;
      // int sum_left_max=0;
      // int tmp_sum_left=0;
      // int sum_right_max=0;
      // int tmp_sum_right=0;
      // if(left_num<right_num){
      //   cout<<"nomal"<<endl;
      //   for(int i=left_num+1;i<right_num;i++){
      //     max_sum+=nums[i];
      //   }
      //   return max_sum;
      // }
      // else{
      //   for(int i=left_num+1;i++;i<size-1){
      //     tmp_sum_right+=nums[i];
      //     if(sum_right_max<tmp_sum_right){
      //       sum_right_max=tmp_sum_right;
      //     }
      //   }
      //   for(int i=right_num-1;i--;i>=0){
      //     tmp_sum_left+=nums[i];
      //     if(sum_left_max<tmp_sum_left){
      //       sum_left_max=tmp_sum_left;
      //     }
      //   }
      //   return sum_left_max>sum_right_max?sum_left_max:sum_right_max;
      // }

    }

    int OldmaxSubArray(vector<int>& nums) {
      int max_sum=nums[0];
      int tmp_sum=0;
      for(int i=1;i<=nums.size();i++){
        for(int j=0;j<nums.size()-i+1;j++){
          for(int k=0;k<i;k++){
            // cout<<"test :"<<j+k<<endl;
            tmp_sum+=nums[j+k];
          }
          if(tmp_sum>max_sum){
            // cout<<"test sum:"<<max_sum<<endl;

            max_sum=tmp_sum;
          }
          tmp_sum=0;
        }
      }
      return max_sum;
    }

};
