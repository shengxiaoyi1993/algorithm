//
// 37. Sudoku Solver
//
// Write a program to solve a Sudoku puzzle by filling the empty cells.
//
// A sudoku solution must satisfy all of the following rules:
//
//     Each of the digits 1-9 must occur exactly once in each row.
//     Each of the digits 1-9 must occur exactly once in each column.
//     Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
//
// Empty cells are indicated by the character '.'.
//
//
// A sudoku puzzle...
//
//
// ...and its solution numbers marked in red.
//
// Note:
//
//     The given board contain only digits 1-9 and the character '.'.
//     You may assume that the given Sudoku puzzle will have a single unique solution.
//     The given board size is always 9x9.


//思路1
//对于每一格，都设置一个list_bool[9],去除每行每列每块中找到的数，直至找到某个单元，其值为确定，然后刷新
//问题在于仅仅依靠这三个条件，是否就以能找到确定的解，若遍历后发现，可能值最少的单元可能值大于1，则使用尝试的方法确定

//动态规划问题


//具体步骤
//初始化
//遍历一次可能值，找到可能值为确定或者可能值最少的单元 9*9
//若可能值确定，则更改行列块的可能值，重复以上步骤
//若可能值有多个，则取其中一个，更新回退
//以上思路是人为的计算方法，但是逻辑比较复杂，实现过程中也出现也许多冗余部分


//用迭代法实现
//依次遍历每个空格，
//计算出空格的可能值，
//  若可能值大于0从小到大填入可能的值，，则进行后续步骤，
//     是：进行下一个空的填充,迭代法运行
//     否：填入这个空下一个可能值
//  若可能值等于0则返回错误


#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "memory.h"
using namespace std;



class Solution {
public:


  //计算某一空格的可能值
  //所在行，所在列/所在区域均不包含的值
  //初始化一个数组9个false
  //若包含，则将该下表的flag置为true
  //获取为false的下标值，即为结果
  std::vector<int> getValueList(vector<vector<char> >& board ,int v_r,int v_c){
    bool flag[9];
    memset(flag,'\0',sizeof(flag)*sizeof(bool));

    for (size_t c = 0; c < 9; c++) {
      if(board[v_r][c] != '.'){
        flag[board[v_r][c]-'1']=true;
      }
    }

    for (size_t r = 0; r < 9; r++) {
      if(board[r][v_c] != '.'){
        flag[board[r][v_c]-'1']=true;
      }
    }

    size_t r_start=v_r/3*3;
    size_t c_start=v_c/3*3;
    for (size_t r = r_start; r < r_start+3; r++) {
      for (size_t c = c_start; c < c_start+3; c++) {
        if(board[r][c] != '.'){
          flag[board[r][c]-'1']=true;
        }
      }
    }

    std::vector<int> list_ret;
    for (size_t i = 0; i < 9; i++) {
      if(!flag[i]){
        list_ret.push_back(i);
      }
    }
    return list_ret;

  }

  bool isFull(vector<vector<char> >& board){
    for (size_t r = 0; r < 9; r++) {
      for (size_t c = 0; c < 9; c++) {
        if(board[r][c] == '.'){
          return false;
        }
      }
    }
    return true;
  }

  //v_r，v_c 点之前的数据均被填充
  bool isValid(vector<vector<char> >& board,int v_r,int v_c){
    //find fist point
    //cal values
    //map value

    int r_cur=-1;
    int c_cur=-1;

    bool fbreak=false;
    for (size_t r = v_r; r < 9; r++) {
      for (size_t c = 0; c < 9; c++) {
        // cout<<"r: "<<r<<" c： "<<c<<endl;
        if(board[r][c] == '.'){
          r_cur =r;
          c_cur=c;
          fbreak=true;
          break;
        }

      }
      if(fbreak){
        break;
      }
    }

    if(!fbreak){
      return true;
    }
    //cal values
    std::vector<int> list_value=getValueList(board,r_cur,c_cur);

    //map value
    for (size_t i = 0; i < list_value.size(); i++) {
      board[r_cur][c_cur]=list_value[i]+'1';
      if(isValid(board,r_cur,c_cur)){
        // std::cout << "func end" << '\n';
        return true;
      }
      else{
        board[r_cur][c_cur]='.';
      }
    }
    return false;

  }

  // bool confirm[9][9];
  void solveSudoku(vector<vector<char> >& board) {
    bool flag= isValid(board,0,0);
    // std::cout << "flag:" <<flag<< '\n';
  }



};
