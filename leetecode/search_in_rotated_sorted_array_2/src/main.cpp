#include "solution.h"

int main(int argc, char const *argv[])
{
  Solution tmp;

//  vector<int> nums = {2,5,6,0,0,1,2};
//  int target=0;

//  vector<int> nums = {2,5,6,0,0,1,2};
//  int target=3;

    vector<int> nums = {0,0,0,0,0,0,0,0};
    int target=3;

  bool ret= tmp.search(nums,target);
  std::cout<<"ret:"<<ret<<endl;



  return 0;
}
