#include "solution.h"

int main(int argc, char const *argv[])
{
    Solution tmp;

//   int n = 1, k = 1;
//   int n = 4, k = 2;
    int n = 5, k = 3;





   vector<vector<int>> ret= tmp.combine(n,k);

   cout<<"ret.size:"<<ret.size()<<endl;
   for (size_t i=0;i<ret.size();i++) {
     for (size_t j=0;j<ret[i].size();j++) {
       cout<<ret[i][j]<<" ";
     }
     cout<<endl;
   }
   cout<<endl;



    
    return 0;
}
