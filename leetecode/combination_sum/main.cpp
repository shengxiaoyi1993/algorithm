#include <iostream>
#include <string>
#include <vector>
#include"solution.hpp"
using namespace std;
int main(){
  Solution tmp;
  int vals[]={2,3,5};
  int size_vals=3;
  vector<int> candidates;
  for (size_t i = 0; i < size_vals; i++) {
    candidates.push_back(vals[i]);
  }
  int target=8;
  for (size_t i = 0; i < candidates.size(); i++) {
    cout<<i<<": "<<candidates[i]<<endl;
  }

  vector<vector<int> > results= tmp.combinationSum(candidates,target);
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
