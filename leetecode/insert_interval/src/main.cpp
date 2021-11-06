#include "solution.h"

int main(int argc, char const *argv[])
{
  Solution tmp;


//  vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
//  vector<int> newInterval = {4,8};

//  vector<vector<int>> intervals = {};
//  vector<int> newInterval = {5,7};

//  vector<vector<int>> intervals = {{1,5}};
//  vector<int> newInterval = {2,3};

  vector<vector<int>> intervals ={{1,3},{6,9}};
  vector<int> newInterval = {2,5};

   vector<vector<int>> L_RET= tmp.insert(intervals,newInterval);
   for (auto it:L_RET) {
     cout<<it[0]<<" "<<it[1]<<endl;
   }



  return 0;
}
