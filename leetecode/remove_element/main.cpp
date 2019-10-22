#include<iostream>
#include<string>
#include<vector>
#include"solution.hpp"
using namespace std;
int main(){
  vector<int>  numlist={3,2,2,3};
  Solution tmp;
  int count;
  count=tmp.removeElement(numlist,3);
  cout<<"count:"<<count<<endl;
  for(int i=0;i<count;i++){
    cout<<numlist[i]<<" ";
  }
  cout<<endl;
  return 0;
}
