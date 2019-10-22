#include <iostream>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
      if(n==1){
        return "1";
      }
      else{
        string tmp_string=countAndSay(n-1);
        string result="1";
        // string result='1'+tmp_string[0];
        int    result_count=0;
        char   tmp_num=tmp_string[0];
        result=result+tmp_num;
        for(int i=1;i<tmp_string.size();++i){
          if(tmp_string[i]==tmp_num){
            result[result_count*2]=(char )(result[result_count*2]+1);
          }
          else{
            result_count++;
            result=result+"1"+tmp_string[i];
            tmp_num=tmp_string[i];
          }
          // cout<<i<<" runing:"<<result<<endl;
        }
        return result;
      }
    }
};
