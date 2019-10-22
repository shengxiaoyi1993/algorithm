#include<iostream>
#include"solution.hpp"
#include<string>
using namespace std;
int main(){
  Solution tmp;
  string haystack = "a";
  string needle = "a";
  cout<<"result:"<<tmp.strStr(haystack,needle);
  return 0;
}
