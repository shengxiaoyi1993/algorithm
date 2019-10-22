#include<iostream>
#include<string>
#include"solution.hpp"
using namespace std;
int main(){
  Solution tmp;
  for(int i=2;i<100;i++){
    cout<<i<<": "<<tmp.climbStairs(i)<<endl;
  }
  return 0;
}
