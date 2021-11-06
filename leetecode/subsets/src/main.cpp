#include "solution.h"

int main(int argc, char const *argv[])
{
    Solution tmp;
    vector<int> nums={1,2,3};

    vector<vector<int>> arr_ret=tmp.subsets(nums);
    for (auto iti:arr_ret) {

      for (auto itj:iti) {
        cout<<itj<<" ";
      }
      cout<<endl;
    }
    cout<<endl;


    
    return 0;
}
