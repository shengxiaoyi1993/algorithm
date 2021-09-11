#include<iostream>
#include<string>
#include <vector>

#include"solution.hpp"
using namespace std;
int main(){
  vector<string> strs;
  strs.push_back("eat");
  strs.push_back("tea");
  strs.push_back("ate");
  strs.push_back("nat");
  strs.push_back("bat");
  strs.push_back("tan");

  Solution tmp;
  vector<vector<string> >  mat=tmp.groupAnagrams(strs);
  for (size_t i = 0; i < mat.size(); i++) {
    for (size_t j = 0; j < mat[i].size(); j++) {
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;
  return 0;
}
