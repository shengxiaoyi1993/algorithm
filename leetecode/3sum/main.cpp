#include<iostream>
#include<string>
#include<vector>
#include"solution.hpp"
using namespace std;
int main(){
  int array[124]={-5,14,1,-2,11,
  11,-10,3,-6,0,
  3,-4,-9,-13,-8,
  -7,9,8,-7,11,
  12,-7,4,-7,-1,
  -5,13,1,-2,8,
  -13,0,-1,3,13,
  -13,-1,10,5,1,
  -13,-15,12,-7,-13,
  -11,-7,3,13,1,
  0,2,1,11,10,
  8,-8,1,-14,-3,
  -6,-12,12,0,6,
  2,2,-9,-3,14,
  -1,-9,14,-4,-1,
  8,-8,7,-4,12,
  -14,3,-9,2,0,
  -13,-13,-1,3,-12,
  11,4,-9,8,11,
  5,-5,-10,3,-1,
  -11,-13,5,-12,-10,
  11,11,-3,-5,14,
  -13,-4,-5,-7,6,
  2,-13,0,8,-3,
  4,4,-14,2};
  vector<int> v(array,array+124);
  Solution tmp;
  vector<vector<int>> res= tmp.threeSum(v);
  for(vector<vector<int>>::iterator it = res.begin(); it != res.end(); it++){
    for (vector<int>::iterator it_sub = (*it).begin(); it_sub != (*it).end(); it_sub++){
      cout<<*it_sub<<" ";
    }
    cout<<endl;
  }



  return 0;
}
