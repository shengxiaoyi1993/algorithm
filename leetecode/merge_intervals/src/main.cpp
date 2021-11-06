#include "solution.h"

int main(int argc, char const *argv[])
{
    Solution tmp;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
//    vector<vector<int>> intervals = {{1,4},{4,5}};

//        vector<vector<int>> intervals = {{1,4},{0,2},{3,5}};


//    vector<vector<int>> intervals = {{2,3},{4,5},{6,7},{8,9},{1,10}};

//    vector<vector<int>> intervals = {{5,5},{1,3},{3,5},{4,6},{1,1},{3,3},{5,6},{3,3},{2,4},{0,0}};


   vector<vector<int>> l_ret= tmp.merge(intervals);

   for (auto it:l_ret) {
     std::cout<<it[0]<<" "<<it[1]<<std::endl;
   }


    
    return 0;
}

