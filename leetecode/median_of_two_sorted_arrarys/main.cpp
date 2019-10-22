#include<iostream>
#include<string>
#include<vector>
#include"solution.hpp"
using namespace std;

int main(){
  string tmp_string;
  // cin>>tmp_string;
  // cout<<"there is input:"<<tmp_string<<endl;

int n1[2]={1,2};
vector<int> nums1(n1,n1+2);

int n2[2]={0,3};
vector<int> nums2(n2,n2+2);

Solution tmp;
cout<<"result:"<<tmp.findMedianSortedArrays(nums1,nums2)<<endl;


  return 0;

}
