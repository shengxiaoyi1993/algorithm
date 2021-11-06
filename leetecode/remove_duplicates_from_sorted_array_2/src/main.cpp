#include "solution.h"

int main(int argc, char const *argv[])
{
    Solution tmp;


//    vector<int> nums={0,0,1,1,1,1,2,3,3};
    vector<int> nums={1,1,1,2,2,3};




   int valid_length= tmp.removeDuplicates(nums);
   cout<<"valid_length:"<<valid_length<<endl;
   for (auto it:nums) {
     cout<<it<<" ";
   }
   cout<<endl;


    
    return 0;
}
