#include <vector>
#include <iostream>
#include <vector>

using namespace std;






/// solution 0
/// keep the position in a list ,then save the num to list
/// (n-1)[x+1] (n-1)(y+1) (n-3)(x-1) (n-3)(y-1)
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    int count=1;
    int *max=new int[n*n];
    int start_x=0;
    int start_y=0;
    int length=n;
    while (count<=n*n) {


      if (length == 1) {
        max[start_y*n+start_x]=count;
        break;
      }
      else {
        for (int i=0;i<length;i++) {
          max[start_y*n+start_x+i]=count;
          count++;
        }


        for (int i=1;i<length;i++) {
          max[(start_y+i)*n+start_x+length-1]=count;
          count++;
        }


        for (int i=1;i<length;i++) {
          max[(start_y+length-1)*n+start_x+length-1-i]=count;
          count++;
        }

        for (int i=1;i<length-1;i++) {
          max[(start_y+length-1-i)*n+start_x]=count;
          count++;
        }



        length-=2;
        start_x++;
        start_y++;

      }


    }



    vector<vector<int>> l_ret;

    for (int i=0;i<n;i++) {
      l_ret.push_back(vector<int>(max+i*n,max+i*n+n));
    }

    delete []  max;
    max=nullptr;
    return l_ret;

  }
};
