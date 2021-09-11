

#include<iostream>
#include<string>
#include"solution.hpp"
using namespace std;
int main(){
  Solution tmp;
  string a="dfgdhdfgdfgreykikthghvmhghvggttyerdgffjtfhjygtygjykyghjghgkytit";
  string b="dfg*ykikth*hgh?ggt?yer?g*gtygjykyghjghgkytit";

  cout<<"result:"<<tmp.isMatch(a,b)<<endl;;
  return 0;
}
