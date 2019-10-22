#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
      int count=0;
      int flag=0;
        for(int i=s.size()-1;i>=0;i--){
          if(isalpha(s[i])){
            if(flag==0){
              flag=1;
              for(int j=i;j>=0;j--){
                if(isalpha(s[j])){
                  count++;
                }
                else{
                  break;
                }
              }
              break;
            }
            else{
              break;
            }
          }
          else{
            continue;
          }
        }
        return count;
    }

};
