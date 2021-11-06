#include <vector>
#include <iostream>
#include <vector>

using namespace std;


//74. Search a 2D Matrix

//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

//    Integers in each row are sorted from left to right.
//    The first integer of each row is greater than the last integer of the previous row.



//Example 1:

//Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
//Output: true

//Example 2:

//Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
//Output: false



//Constraints:

//    m == matrix.length
//    n == matrix[i].length
//    1 <= m, n <= 100
//    -104 <= matrix[i][j], target <= 104

/// 二分法查找
/// 首先查找到所在行
/// 然后找到所在列

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    size_t rows=matrix.size();
    size_t cols=matrix[0].size();

    size_t rows_s=0;
    size_t rows_b=rows-1;


    while (rows_s<rows_b) {
      int row_tmp=(rows_s+rows_b)/2;
      if (target<=matrix[row_tmp][cols-1]) {
        rows_b=row_tmp;
      }
      else{
        rows_s=row_tmp+1;
      }
    }


    size_t rows_target=rows_s;
    if (rows_s == rows_b) {
      rows_target=rows_s;
    }
    else{
      return false;
    }

    size_t cols_s=0;
    size_t cols_b=cols-1;


    while (cols_s<=cols_b) {

      int col_tmp=(cols_s+cols_b)/2;
//      cout<<"cols_s:"<<cols_s
//         <<" cols_b:"<<cols_b
//        <<endl;


      if (target == matrix[rows_target][col_tmp]) {


        return true;
      }
      else if(target < matrix[rows_target][col_tmp])
      {
        if (col_tmp == 0) {
          break;
        }
        cols_b=col_tmp-1;

      }
      else{
        if (cols_b == 0) {
          break;
        }
        cols_s=col_tmp+1;
      }
    }


    if (cols_s == cols_b) {
      if (target == matrix[rows_target][cols_s]) {
        return true;
      }
      else{
        return false;
      }
    }


    return false;

  }
};
