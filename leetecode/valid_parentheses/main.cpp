#include<iostream>
#include<string>
#include<vector>
#include"valid_parentheses.hpp"
using namespace std;
int main(){
  Solution tmp;
  string input="{[]}";
  cout<<tmp.isValid(input)<<endl;
  return 0;
}
