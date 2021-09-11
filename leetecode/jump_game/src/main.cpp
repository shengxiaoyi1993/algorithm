#include "solution.h"

int main(int argc, char const *argv[])
{
    Solution tmp;

    vector<int> nums={2,3,1,1,4};
//    vector<int> nums={3,2,1,0,4};
//    vector<int> nums={0};



    bool ret=tmp.canJump(nums);
    if (ret) {
      std::cout<<"canJump"<<std::endl;
    }
    else{
      std::cout<<"canNotJump"<<std::endl;
    }


    
    return 0;
}
