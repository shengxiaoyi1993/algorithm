#include<iostream>
#include<string>
#include<vector>
#include"longest_common_prefix.hpp"
using namespace std;
int main(){
  string str;
  vector<string> stringlist;
  stringlist.push_back("flower");
  stringlist.push_back("flow");
  stringlist.push_back("flight");

  for(int i=0;i<stringlist.size();i++){
    cout<<stringlist[i]<<endl;
  }
  Solution tmp;
  cout<<"longestCommonPrefix:"<<tmp.longestCommonPrefix(stringlist)<<endl;
  return 0;
}
