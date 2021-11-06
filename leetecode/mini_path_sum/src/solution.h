#include <vector>
#include <iostream>
#include <vector>

using namespace std;


//64. Minimum Path Sum

//Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right,
//which minimizes the sum of all numbers along its path.

//Note: You can only move either down or right at any point in time.



//Example 1:

//Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
//Output: 7
//Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

//Example 2:

//Input: grid = [[1,2,3],[4,5,6]]
//Output: 12



//Constraints:

//    m == grid.length
//    n == grid[i].length
//    1 <= m, n <= 200
//    0 <= grid[i][j] <= 100

///构造一个矩阵array_sum，大小同array_num，每点用于记录到达该点的sum,初始值为0
/// 到达该点的sum(i,j) = min(sum(i-1,j),sum(i,j-i))+num(i,j)
///
/// 过程
/// 先构造
/// 计算第一行，第一列
/// 从第二行，第二列逐点计算，直至完成所有点的计算，输出sum(w-1,h-1)的

class Solution {
public:

  int minPathSum(vector<vector<int>> array_num)
  {
    int h=array_num.size();
    int w=array_num[0].size();

    vector<vector<int>> array_sum(h,vector<int>(w,0));

    array_sum[0][0]=array_num[0][0];
    for (size_t i=1;i<h;i++) {
      array_sum[i][0]=array_num[i][0]+array_sum[i-1][0];
    }

    for (size_t i=1;i<w;i++) {
      array_sum[0][i]=array_num[0][i]+array_sum[0][i-1];
    }

    for (size_t ih=1;ih<h;ih++) {
      for (size_t iw=1;iw<w;iw++) {
        array_sum[ih][iw]=array_num[ih][iw]
            +(array_sum[ih-1][iw]<array_sum[ih][iw-1]
            ?array_sum[ih-1][iw]:array_sum[ih][iw-1]);
      }
    }
    return array_sum[h-1][w-1];
  }

};
