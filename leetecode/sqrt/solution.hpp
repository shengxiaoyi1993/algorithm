#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
      if(x==1){
        return 1;
      }

      int left =0;
      int right=x;
      int mid=(left+right*1.0)*1.0/2;
      while(!(left==mid||mid==right)){
        cout<<"left:"<<left<<" mid:"<<mid<<" right:"<<right<<endl;
        if(mid*1.0*mid*1.0>x){
          right=mid;
          mid=(left+right*1.0)*1.0/2;
        }
        else if(mid*1.0*mid<x){
          left=mid;
          mid=(left+right*1.0)*1.0/2;
        }
        else{
          return mid;
        }
      }
      return left;
    }
};
