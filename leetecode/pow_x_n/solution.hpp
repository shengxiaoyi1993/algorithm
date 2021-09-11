#include <iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {

      if (x==0 && n!=0) {
        return 0;
      }
      else if (n==0) {
        return 1;
      }

      if (n>0) {
        double sum=1;
        for (int i=0;i<n;i++) {
          sum*=x;
        }
        return sum;
      }
      else{
        return 1.0/myPow(x,-n);
      }
    }
};
