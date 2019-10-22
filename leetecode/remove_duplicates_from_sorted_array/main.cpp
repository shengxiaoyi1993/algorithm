#include<iostream>
#include"remove_duplicates_from_sorted_array.hpp"
#include<string>
#include<vector>
using namespace std;
int main(){
  Solution tmp;
  vector<int> numlist={0,0,1,1,1,2,2,3,3,4};
  // numlist.push_back(1);
  // numlist.push_back(1);
  // numlist.push_back(2);

  cout<<"size:"<<tmp.removeDuplicates(numlist);
  for(int i=0;i<numlist.size();i++){
    cout<<numlist[i]<<" "<<endl;
  }
  return 0;
}
