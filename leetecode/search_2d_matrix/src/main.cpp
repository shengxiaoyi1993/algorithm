#include "solution.h"

int main(int argc, char const *argv[])
{
    Solution tmp;


//    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
//    int target = 3;

    vector<vector<int>> matrix = {{1,1}};
    int target = 0;
    bool ret=tmp.searchMatrix(matrix,target);
    std::cout<<"ret:"<<ret<<endl;

    return 0;
}
