#include "solution.h"

int main(int argc, char const *argv[])
{
  Solution tmp;



  vector<vector<int>> l_ret= tmp.generateMatrix(4);
  for (auto it:l_ret) {
    for (auto it_in:it) {
      std::cout<<it_in<<" ";
    }
    std::cout<<std::endl;
  }


  return 0;
}

//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.



//Example 1:

//Input: n = 3
//Output: [[1,2,3],[8,9,4],[7,6,5]]

//Example 2:

//Input: n = 1
//Output: [[1]]



//Constraints:

//    1 <= n <= 20
