#include<iostream>
#include<string>
#include <vector>
#include"solution.hpp"
using namespace std;

std::vector<char> fromRow(char v0,char v1,char v2,char v3,char v4,char v5,char v6,char v7,char v8){
  std::vector<char> list;
  list.push_back(v0);
  list.push_back(v1);
  list.push_back(v2);
  list.push_back(v3);
  list.push_back(v4);
  list.push_back(v5);
  list.push_back(v6);
  list.push_back(v7);
  list.push_back(v8);
  return list;
}

int main(){
  vector<vector<char> > board;
  board.push_back(fromRow('5','3','.','.','7','.','.','.','.'));
  board.push_back(fromRow('6','.','.','1','9','5','.','.','.'));
  board.push_back(fromRow('.','9','8','.','.','.','.','6','.'));
  board.push_back(fromRow('8','.','.','.','6','.','.','.','3'));
  board.push_back(fromRow('4','.','.','8','.','3','.','.','1'));
  board.push_back(fromRow('7','.','.','.','2','.','.','.','6'));
  board.push_back(fromRow('.','6','.','.','.','.','2','8','.'));
  board.push_back(fromRow('.','.','.','4','1','9','.','.','5'));
  board.push_back(fromRow('.','.','.','.','8','.','.','7','9'));

  Solution tmp;
  tmp.solveSudoku(board);

  std::cout << "result:" << '\n';

  for (size_t r = 0; r < 9; r++) {
    for (size_t c = 0; c < 9; c++) {
      cout<<board[r][c]<<" ";
    }
    cout<<endl;
  }
  cout<<endl;

  return 0;
}
