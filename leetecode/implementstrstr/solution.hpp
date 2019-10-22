#include <iostream>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
      int haystack_size=haystack.size();
      int needle_size=needle.size();
      if(needle_size==0){
        return 0;
      }
      else{
        for(int i=0;i<haystack_size-needle_size+1;i++){
          if(IsEqual(haystack,needle,i)){
            return i;
          }
        }
      }
      return -1;
    }
    bool IsEqual(string longstr,string shortstr,int del_num){
      for(int i=0;i<shortstr.size();i++){
        if(i+del_num>=longstr.size()){
          return false;
        }
        else{
          if(longstr[i+del_num]!=shortstr[i]){
            return false;
          }
        }
      }
      return true;
    }
};
