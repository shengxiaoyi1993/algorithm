#include "solution.h"

int main(int argc, char const *argv[])
{
  Solution tmp;

  //    tmp.solveNQueens(0);

  //    [[1,1,1],[1,0,1],[1,1,1]]



//  vector<vector<int>> l_num={{1,1,1},{1,0,1},{1,1,1}};

  vector<vector<int>> l_num={{0,1,2,0},{3,4,5,2},{1,3,1,5}};

  tmp.setZeroes(l_num);

  for (size_t i=0;i<l_num.size();i++) {
    for (size_t j=0;j<l_num[0].size();j++) {
      cout<<l_num[i][j]<<" ";
    }
    cout<<endl;
  }


  return 0;
}
