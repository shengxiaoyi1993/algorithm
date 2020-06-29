// Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
//
//     Each row must contain the digits 1-9 without repetition.
//     Each column must contain the digits 1-9 without repetition.
//     Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
//
//
// A partially filled sudoku which is valid.
//
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
// Example 1:
//
// Input:
// [
//   ["5","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// Output: true
//
// Example 2:
//
// Input:
// [
//   ["8","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being
//     modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
//
// Note:
//
//     A Sudoku board (partially filled) could be valid but is not necessarily solvable.
//     Only the filled cells need to be validated according to the mentioned rules.
//     The given board contain only digits 1-9 and the character '.'.
//     The given board size is always 9x9.
//
// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/valid-sudoku
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (size_t i = 0; i < 9; i++) {
          std::vector<bool> list_bool(10,false);
          for (size_t j = 0; j < 9; j++) {
            if(board[i][j] == '.'){
              continue;
            }
            if(list_bool[board[i][j]-'0']==true){
              return false;
            }
            else{
              list_bool[board[i][j]-'0']=true;
            }
          }

        }

        for (size_t i = 0; i < 9; i++) {
          std::vector<bool> list_bool(10,false);
          for (size_t j = 0; j < 9; j++) {
            if(board[j][i] == '.'){
              continue;
            }

            if(list_bool[board[j][i]-'0']==true){
              return false;
            }
            else{
              list_bool[board[j][i]-'0']=true;
            }
          }
        }
        for (size_t r = 0; r < 3; r++) {
          for (size_t c = 0; c < 3; c++) {
            std::vector<bool> list_bool(10,false);

            for (size_t sub_r = 0; sub_r < 3; sub_r++) {
              for (size_t sub_c = 0; sub_c < 3; sub_c++) {
                size_t tmp_c=sub_c+c*3;
                size_t tmp_r=sub_r+r*3;
                if(board[tmp_r][tmp_c] == '.'){
                  continue;
                }
                if(list_bool[board[tmp_r][tmp_c]-'0']==true){
                  return false;
                }
                else{
                  list_bool[board[tmp_r][tmp_c]-'0']=true;
                }
              }
            }
          }

        }
        return true;
    }
};
