#include <vector>
#include <iostream>
#include <vector>
#include <memory.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

using namespace std;


//73. Set Matrix Zeroes

//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

//You must do it in place.



//Example 1:

//Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
//Output: [[1,0,1],[0,0,0],[1,0,1]]

//Example 2:

//Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
//Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]



//Constraints:

//    m == matrix.length
//    n == matrix[0].length
//    1 <= m, n <= 200
//    -231 <= matrix[i][j] <= 231 - 1



//Follow up:

//    A straightforward solution using O(mn) space is probably a bad idea.
//    A simple improvement uses O(m + n) space, but still not the best solution.
//    Could you devise a constant space solution?




class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      if (matrix.size() == 0) {
        return;
      }

      size_t rows=matrix.size();
      size_t cols=matrix[0].size();

      char *arr=(char*)malloc(rows*cols*sizeof (char));
      memset(arr,1,rows*cols*sizeof (char));

      for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
          if (matrix[i][j] == 0) {
            /// 先设置竖向
            for (int l=0;l<rows;l++) {
              arr[l*cols+j]=0;
            }

            for (int m=0;m<cols;m++) {
              arr[i*cols+m]=0;

            }

          }

        }
      }

      /// 将辅助矩阵中的值逐个相乘
      for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
          matrix[i][j]*=arr[i*cols+j];
        }
      }
      return ;

    }
};
