#include <iostream>
using namespace std;
#include<string>
#include<vector>
#include <algorithm>
// 31. Next Permutation
//
// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
// The replacement must be in-place and use only constant extra memory.
//
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1


//optimize method
//在原字符串上进行操作，减少拷贝和重复计算
//循环标示符改成int，减少计算


class Solution {
public:


    bool insertNum(vector<int>& nums,int v_num){
      bool isfound=false;
      size_t pos=0;
      for (size_t j = 0; j < nums.size(); j++) {
        int i=nums.size()-1-j;

        if(nums[i]>v_num){
          isfound=true;
          pos=i;
          break;

        }
      }

      if(isfound == false){
        nums.insert(nums.begin()+pos,v_num);
        return isfound;
      }
      else{
        int tmp=nums[pos];
        nums[pos]=v_num;
        nums.insert(nums.begin(),tmp);
        reverse(nums.begin()+1,nums.end());
        return true;
      }

    }

    void nextPermutation(vector<int>& nums) {
      //从末尾开始比较，
      // 若总是从大到小排列则没有，
      //  若发现有第一位小于第二位，则找到大于第一位的数，然后将后几位从大到小排列

      std::vector< int> nums_sup;
      bool flag=false;
      for (size_t j = 0; j < nums.size(); j++) {
        int i=nums.size()-1-j;
        if(flag == true){
          nums_sup.insert(nums_sup.begin(),nums[i]);

        }
        else{
          flag = insertNum(nums_sup,nums[i]);

        }
          // for (size_t i = 0; i < nums_sup.size(); i++) {
          //   cout<<nums_sup[i]<<" ";
          // }
          // cout<<endl;
        /* code */
      }

      if(flag == false){
        reverse(nums.begin(),nums.end());
      }
      else{
        for (size_t i = 0; i < nums.size(); i++) {
          nums[i]=nums_sup[i];
          /* code */
        }
      }
    }
};
