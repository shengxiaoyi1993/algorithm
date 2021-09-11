#include "solution.h"






int main(int argc, char const *argv[])
{
  Solution tmp;

  //    tmp.solveNQueens(0);
  //    tmp.spiralOrder();

//  vector<vector<int>> matrix={
//    {1,2,3},{4,5,6},{7,8,9}
//  };

  vector<vector<int>> matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12}};

  vector<int>  l_res= tmp.spiralOrder(matrix);

  for (auto it_j:l_res) {
    std::cout<<it_j<<std::endl;
  }



  return 0;
}
