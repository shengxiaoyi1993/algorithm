#include<iostream>
#include<string>
#include<vector>
#include"solution.hpp"
using namespace std;
int main(){

  Solution tmp;
  int array[4]={-1, 2, 1, -4};
  vector<int> v_array(array,array+4);
  cout<<tmp.threeSumClosest(v_array,3)<<endl;
  return 0;
}
