#include<iostream>
#include<string>
#include <vector>
#include"solution.hpp"
using namespace std;
int main(){
  Solution tmp;

  const int size=4;
  int n0[size]={5, 1, 9,11};
  int n1[size]={2, 4, 8,10};
  int n2[size]={13, 3, 6, 7};
  int n3[size]={15,14,12,16};

  vector<vector<int> > matrix;
    vector<int> tmpnums;
    for (size_t j = 0; j < size; j++) {
      tmpnums.push_back(n0[j]);
    }
    matrix.push_back(tmpnums);
    tmpnums.clear();
    for (size_t j = 0; j < size; j++) {
      tmpnums.push_back(n1[j]);
    }
    matrix.push_back(tmpnums);
    tmpnums.clear();

    for (size_t j = 0; j < size; j++) {
          tmpnums.push_back(n2[j]);
        }
        matrix.push_back(tmpnums);
        tmpnums.clear();

        for (size_t j = 0; j < size; j++) {
              tmpnums.push_back(n3[j]);
            }
            matrix.push_back(tmpnums);
        tmp.rotate(matrix);
        std::cout << "result:" << '\n';
        for (size_t i = 0; i < size; i++) {
          for (size_t j = 0; j < size; j++) {
            cout<<matrix[i][j]<<" ";
            /* code */
          }
          cout<<endl;
          /* code */
        }
        cout<<endl;


  return 0;
}
