#include<iostream>
#include<string>
#include"solution.hpp"
using namespace std;
int main(){
  Solution tmp;
  vector<string> list= tmp.generateParenthesis(3);
  for (size_t i = 0; i < list.size(); i++) {
    cout<<list[i]<<endl;
    /* code */
  }



  return 0;
}
