#include <iostream>
using namespace std;
class Solution {
public:
      int climbStairs(int n) {
        if(n==0){
          return 1;
        }
        else if(n==1){
          return 1;
        }
        else{
          int num_1=1;
          int num_2=1;
          int num_res=0;
          for(int i=2;i<=n;i++){
            num_res=num_1+num_2;
            num_1=num_2;
            num_2=num_res;
          }
          return num_res;
        }
      }



    int climbStairs_2(int n) {
        int num_1=0;
        int num_2=0;
        int count=0;
        for(;num_1>=0;num_2++){
          num_1=n-2*num_2;
          if(num_1>=0){
            count+=fun(num_1+num_2)*1.0/(fun(num_1)*fun(num_2)*1.0);
          }
          else{
            return count;
          }
        }
    }


    double fun(int n){
      double result=1;
      if(n==0){
        return 1;
      }
      else{
        for(int i = 1;i <= n;i++){
          result=i*result*1.0;
        }
        return result;
      }
    }

};
