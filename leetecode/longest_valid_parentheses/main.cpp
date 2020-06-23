#include<iostream>
#include<string>
#include"solution.hpp"
using namespace std;
int main(){
  Solution tmp;
  string a=")(((())))))(";
  cout<<"result:"<<tmp.longestValidParentheses(a);
  return 0;
}
