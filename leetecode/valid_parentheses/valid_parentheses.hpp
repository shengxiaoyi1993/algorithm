#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
bool isValid(string s) {
  vector<char> tmp;
  for(int i=0;i<s.size();i++){
    // for(int j=0;j<tmp.size();j++){
    //   cout<<tmp[j];
    // }
    // cout<<endl;
    if(s[i]=='('||s[i]=='{'||s[i]=='['){
      tmp.push_back(s[i]);
    }
    else if(s[i]==')'||s[i]=='}'||s[i]==']'){
      if(!tmp.empty()){
        if(tmp.at(tmp.size()-1)==oppositebracket(s[i])){
          tmp.pop_back();
        }
        else{
          return false;
        }
      }
      else{
        return false;
      }
    }
  }
  if(!tmp.size()){
    return true;
  }
  else{
    return false;
  }
}

char oppositebracket(char ch){
  if(ch==')'){
    return '(';
  }
  else if(ch=='}'){
    return '{';
  }
  else if(ch==']'){
    return '[';
  }
}

};
