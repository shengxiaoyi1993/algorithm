#include<iostream>
#include<string>

#include"solution.hpp"
using namespace std;
int main(){
  Solution obj;
  string tmp="pewwwbw";
  int res=obj.lengthOfLongestSubstring(tmp);
    cout<<tmp<<":"<<res<<endl;
    return 0;
}
