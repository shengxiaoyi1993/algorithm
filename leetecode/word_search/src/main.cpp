#include "solution.h"

int main(int argc, char const *argv[])
{
  Solution tmp;

//  vector<vector<char>> board ={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
//  string  word = "ABCCED";

//  vector<vector<char>> board ={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
//  string  word = "SEE";

//  vector<vector<char>> board ={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
//  string  word = "ABCB";

//  vector<vector<char>> board ={{'A'}};
//  string  word = "A";



  vector<vector<char>> board ={{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'}};
  string  word = "AAAAAAAAAAAABAA";

  //      vector<char> tmp={"A","B","C","E"};

  int ret= tmp.exist(board,word);
  std::cout<<"ret:"<<ret<<endl;



  return 0;
}
