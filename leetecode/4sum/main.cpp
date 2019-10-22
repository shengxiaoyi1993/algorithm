#include<iostream>
#include<string>
#include<vector>
#include"solution.hpp"

using namespace std;
int main(){
  Solution tmp;
  vector<int> list_input={4,-3,-5,4,4,-1,1,-4};
  vector<vector<int>> lis_res=tmp.fourSum(list_input,4);
  for (size_t i = 0; i < lis_res.size(); i++) {
    for (size_t j = 0; j < 4; j++) {
      cout<<lis_res[i][j]<<" ";
    }
    cout<<endl;

  }
  return 0;
}
