#include<iostream>
#include<string>
#include"solution.hpp"
using namespace std;
int main(){

  while (1) {
    string tmp_string;
    cin>>tmp_string;
    cout<<"there is input:"<<tmp_string<<endl;
    Solution tmp;

    string res=tmp.longestPalindrome(tmp_string);
    cout<<"longestPalindrome:"<<res<<endl;
  }

  return 0;
}
