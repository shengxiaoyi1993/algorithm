#include "solution.h"

int main(int argc, char const *argv[])
{
    Solution tmp;

//    vector<vector<int>> array_num={{1,3,1},{1,5,1},{4,2,1}};
    vector<vector<int>> array_num={{1,2,3},{4,5,6}};


    int ret=tmp.minPathSum(array_num);

    cout<<"ret:"<<ret<<endl;


    
    return 0;
}
