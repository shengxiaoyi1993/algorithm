#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int length=nums.size();
      if(length<=2){
        return -1;
      }
      sort(nums.begin(), nums.end());
      int sum_res=nums[0]+nums[1]+nums[2];
      int min_dis=abs(sum_res-target);

      for(int i=0;i<length;i++){
        printf("%d\n", nums[i]);
      }

      for(int i=0;i<length-2;i++){
        for(int j=i+1;j<length-1;j++){
          int num_tmp=target-nums[i]-nums[j];
          int num_third=closestNum(nums,num_tmp,j+1);
          printf("%d %d %d\n",nums[i],nums[j],num_third );

          int dis_tmp=abs(num_third-num_tmp);

          if(min_dis>dis_tmp){
            min_dis=dis_tmp;
            sum_res=nums[i]+nums[j]+num_third;
          }

          if(min_dis==0){
            // printf("%d %d %d\n",nums[i],nums[j],num_third );
            return sum_res;
          }
        }
      }
    }

    int closestNum(vector<int>& array, int target,int j_num){


      int left =j_num;
      int right = array.size()-1;
      if(array[left]>target){
        return array[right];
      }
      if(array[right]<target){
        return array[right];
      }

      while(left<right-1){
        printf("left:%d\ns",left);
        printf("right:%d\n",right);
        int mid=(left+right+1)/2;

        if(array[mid]>target){
          right=mid;
        }
        else if(array[mid] <target){
          left=mid;
        }
        else{
          return array[mid];
        }

      }
      if(target-array[left]>array[right]-target){
        return array[right];
      }
      else{
        return array[left];
      }

    }
};

// class Solution {
// public:
//     int threeSumClosest(vector<int>& nums, int target) {
//       int len=nums.size();
//       if(len<3){
//         return -1;
//       }
//       int sum_res=nums[0]+nums[1]+nums[2];
//       int min_dis=abs(sum_res-target);
//
//       for(int i=1;i<len-2;i++){
//         int sum_tmp=nums[i]+nums[i+1]+nums[i+2];
//         int dis_tmp=abs(sum_tmp-target);
//         if(min_dis<=dis_tmp){
//
//         }
//         else{
//           min_dis=dis_tmp;
//           sum_res=sum_tmp;
//         }
//         cout<<"nums[i]:"<<nums[i]<<" nums[i+1]:"<<nums[i+1]<<" nums[i+2]:"<<nums[i+2]<<
//         " min_dis:"<<min_dis<<" sum_res:"<<sum_res<<endl;
//         if(min_dis==0){
//           break;
//         }
//       }
//       return sum_res;
//     }
// };
