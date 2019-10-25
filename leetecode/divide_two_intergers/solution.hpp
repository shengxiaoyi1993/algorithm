#include <iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>


using namespace std;
class Solution {
public:


    int divide(int dividend, int divisor) {
    // int  INT_MAX =2147483647;
    // int  INT_MIN =-2147483648 ;
      if(divisor ==1){
            return  dividend;
      }
      if(divisor == dividend){
            return 1;
        }
     int value_times=0;

     int flag;
      if(((dividend<0)&&(divisor<0))||((dividend>0)&&(divisor>0))){
        flag=1;
      }
      else{
        flag=-1;
      }
      if(divisor == 0){
        return INT_MAX;
      }


     if(dividend == -2147483648 ){
       if(divisor == -1 ){
         return INT_MAX;
       }
         else if(divisor == 1){
           return INT_MIN;

         }
       else{
         value_times++;
         dividend+=abs(divisor);
       }
     }
     if(divisor == INT_MIN){
       if(dividend == INT_MIN ){
         return 1;
       }
       else{
         return 0;
       }
     }

      int value_dividend=dividend;
      value_dividend=value_dividend>0?value_dividend:(-value_dividend);
      divisor=divisor>0?divisor:(-divisor);

      int value_remain=value_dividend;

      while (divisor<=value_remain) {
        int tmp_times=1;
        int tmp_sum=divisor;
        while ((value_remain>>1)>=(tmp_sum)) {
          tmp_sum=tmp_sum<<1;
          tmp_times<<=1;
        }
        value_remain-=(tmp_sum);
        value_times+=tmp_times;

      }

      if(flag==1){
        return value_times;

      }
      else{
        return -value_times;

      }
    }


};
