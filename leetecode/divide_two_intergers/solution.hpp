#include <iostream>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        int flag=0;

        if(dividend<0){
          flag++;
        }
        if(divisor<0){
          flag++;
        }
        int count=0;

        if(dividend == -2147483648){
          dividend =2147483647;
          divisor=divisor>0?divisor:(-divisor);
          int result=divisor;
          int result_pre=0;
          while (result-1<=dividend&&result>result_pre) {
            count++;
            result+=divisor;
          }

        }
        else{
          dividend=dividend>0?dividend:(-dividend);
          divisor=divisor>0?divisor:(-divisor);
          int result=divisor;
          int result_pre=0;

          while (result<=dividend &&result>result_pre) {
            count++;
            result+=divisor;
          }
        }



        if(flag==0||flag==2){
          return count;
        }
        else{
          return -count;
        }
    }
};
