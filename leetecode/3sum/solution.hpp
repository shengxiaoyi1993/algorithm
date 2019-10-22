#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
static auto x = []() {ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int size=nums.size();
      vector<vector<int>> res;
      if(size<=2){
        return res;
      }

      sort(nums.begin(), nums.end());
      int ceil=size-2;
      for(int i=0;i<ceil;i++){
        if(i>0&&nums[i]==nums[i-1]){continue;}
        int left=i+1;
        int right=size-1;
        while(left<right){
          int sum=nums[i]+nums[left]+nums[right];
          if(sum>0){
            right--;
          }
          else if(sum<0){
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


// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//       vector<vector<int>> res;
//       if(nums.size()<3){
//         return res;
//       }
//       int count_zero= count(nums.begin(),nums.end(),0);
//       if(count_zero>=3){
//         int array_sub[3]={0,0,0};
//         vector<int> res_sub(array_sub,array_sub+3);
//         res.push_back(res_sub);
//       }
//
//
//
//         sort(nums.begin(), nums.end());
//         // for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
//         //   cout<<"it: "<<*it<<endl;
//         //
//         // }
//
//
//
// int num_it_it=0;
//         for (vector<int>::iterator it = nums.begin(); it != nums.end()&&(*it)<0; it++){
//           if(num_it_it==0){
//             num_it_it=(*it);
//           }
//           else{
//             if(num_it_it==(*it)){
//               continue;
//             }
//           }
//           // cout<<"it: "<<*it<<endl;
//           // cout << *it << endl;
//           // sum_tmp+=;
//           for (vector<int>::iterator it_2 = nums.end()-1; it_2 != nums.begin()-1&&(*it_2)>0; it_2--){
//             int sum_tmp=(*it)+(*it_2);
//
//             // cout<<" "<<*it<<" "<<*it_2<<endl;
//
//             // sum_tmp+=(*it_2);
//             if(sum_tmp==0){
//               // cout<<" "<<*it<<0<<" "<<" "<<*it_2<<endl;
//
//               if(count_zero>=1){
//                 int array_sub[3]={*it,0,*it_2};
//                 vector<int> res_sub(array_sub,array_sub+3);
//                 res.push_back(res_sub);
//               }
//               }
//               else if(sum_tmp>0){
//                 for (vector<int>::iterator it_3 = it+1; it_3 != nums.end()&&(*it_3)<0&&(*it_3)<=(*it_2); it_3++){
//                   // cout<<" "<<*it<<" "<<*it_3<<" "<<*it_2<<endl;
//
//                   if(sum_tmp+(*it_3)==0){
//                     int array_sub[3]={*it,*it_3,*it_2};
//                     vector<int> res_sub(array_sub,array_sub+3);
//                     res.push_back(res_sub);
//                     break;
//                   }
//                 }
//               }
//               else{
//                 for (vector<int>::iterator it_3 = it_2-1; it_3 != nums.begin()-1&&(*it_3)>0&&(*it_3)>=(*it); it_3--){
//                   // cout<<" "<<*it<<" "<<*it_3<<" "<<*it_2<<endl;
//
//                   if(sum_tmp+(*it_3)==0 ){
//                     int array_sub[3]={*it,*it_3,*it_2};
//                     vector<int> res_sub(array_sub,array_sub+3);
//                     res.push_back(res_sub);
//                     break;
//                   }
//                 }
//
//               }
//
//           }
//
//         }
//         // cout<<"test"<<endl;
//         if(res.size()>=2){
//                   for (vector<vector<int>>::iterator it= res.begin()+1; it != res.end();){
//
//                     if((*it)==(*(it-1))){
//                       it=res.erase(it);
//                     }
//                     else{
//                       it++;
//                     }
//
//
//             }
//         }
//
//
//         return res;
//
//     }
//
//
// };
