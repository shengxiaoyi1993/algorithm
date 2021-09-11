#include "solution.h"

int main(int argc, char const *argv[])
{
  Solution m;
  int num= m.totalNQueens(9);

//  for (auto it_i:arr) {
//    std::cout<<"<"<<endl;
//    for (auto it_j:it_i) {
//      std::cout<<it_j<<std::endl;
//    }
//    std::cout<<">"<<endl;
//  }

  std::cout<<"num:"<<num<<endl;


    return 0;
}


