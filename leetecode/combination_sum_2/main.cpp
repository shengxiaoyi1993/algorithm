#include<iostream>
#include<string>
#include <vector>
#include <map>
#include"solution.hpp"
using namespace std;

// void testmap(){
//   map<vector<int> ,int> tmpmap;
//   vector<int> tmplist;
//   tmplist.push_back(7);
//   tmplist.push_back(3);
//   tmplist.push_back(79);
//
//   tmpmap[tmplist]=8;
//   tmplist.push_back(9);
//   tmpmap[tmplist]=1;
//
//   for(auto t:tmpmap){
//     for (size_t i = 0; i < t.first.size(); i++) {
//       cout<<t.first[i]<<" ";
//     }
//     cout<<endl;
//     std::cout <<"second:"<<t.second << '\n';
//   }
// }

int main(){
  // testmap();
  Solution tmp;
  int vals[]={10,1,2,7,6,1,5};
  int size_vals=7;
  vector<int> candidates;
  for (size_t i = 0; i < size_vals; i++) {
    candidates.push_back(vals[i]);
  }
  int target=8;
  for (size_t i = 0; i < candidates.size(); i++) {
    cout<<i<<": "<<candidates[i]<<endl;
  }

  vector<vector<int> > results= tmp.combinationSum2(candidates,target);
  std::cout << "main:" << '\n';

  for (size_t i = 0; i < results.size(); i++) {
    std::cout <<i<< ":" <<" ";
    for (size_t j = 0; j < results[i].size(); j++) {
      std::cout << results[i][j] << " ";
    }
    std::cout  << '\n';

  }
  return 0;
}
