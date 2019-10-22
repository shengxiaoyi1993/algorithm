#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int start=0;
    int end=0;
    int max=0;
    int flag=0;
        for(start=0;start<s.size();start){
          for(end=start;end<s.size();end++){
            string tmp_substring=s.substr(start,end-start+1);
            cout<<tmp_substring<<endl;
            if((flag=FindStringRepeat(tmp_substring))==-1){
              cout<<"start:"<<start<<endl;
              cout<<"end:"<<end<<endl;

              max=(max>(end-start+1))?max:(end-start+1);

              continue;
            }
            else{
              start=flag;
              break;
            }
          }
        }
        return max;
    }

    bool IsStringWithoutRepeat(string s){
      for(int i=s.size()-1;i>=0;i--){
        for(int j=0;j<i;j++){
          if(s.at(j)==s.at(i)){
            return false;
          }
        }
      }
      return true;

    }

    int FindStringRepeat(string s){
      for(int i=s.size()-1;i>=0;i--){
        for(int j=0;j<i;j++){
          if(s.at(j)==s.at(i)){
            return i;
          }
        }
      }
      return -1;

    }
};
