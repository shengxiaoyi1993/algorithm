#include "solution.h"

int main(int argc, char const *argv[])
{

  Solution m;
  vector<vector<string> > arr= m.solveNQueens(9);

  for (auto it_i:arr) {
    std::cout<<"<"<<endl;
    for (auto it_j:it_i) {
      std::cout<<it_j<<std::endl;
    }
    std::cout<<">"<<endl;
  }

  return 0;
}
