#include <iostream>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int nums2_i=0;
      int size_1=m;
        for(int i=0;i<=size_1;){
          if(nums2_i>=n){
            break;
          }
          else{
            if(nums2[nums2_i]>nums1[i]){
              i++;
              continue;
            }
            else{
              size_1++;
              for(int j=size_1-1;j>i;j--){
                nums1[j]=nums1[j-1];
              }
              nums1[i]=nums2[nums2_i];
              // nums1.insert(nums1.begin()+i,nums2[nums2_i]);
              i++;
              nums2_i++;
            }
          }
        }
        for(;nums2_i<n;nums2_i++){
          nums1[m+nums2_i]=nums2[nums2_i];
        }
    }
};
