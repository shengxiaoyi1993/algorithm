#include "solution.h"
#include <algorithm>
#include <iostream>
 #include <vector>

int main(int argc, char const *argv[])
{
    Solution tmp;

    std::vector<int>  nums = {2,0,2,1,1,0};
//    std::vector<int>  nums = {2,0,1};
//    std::vector<int>  nums = {0,};



    tmp.sortColors(nums);

    for (auto it:nums ) {
      std::cout<<it<<" ";
    }
    std::cout<<std::endl;
    
    return 0;
}
