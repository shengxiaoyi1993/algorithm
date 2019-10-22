#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int len=str.size();
        int count=0;
        int res=0;
        int flag=1;
        while(count<len){
          if(str[count]>='0'&&str[count]<='9'){
            cout<<"count: "<<count<<" "<<str[count]<<endl;
            if(flag>0){
              if((res>214748364)||(res==214748364&&str[count]>7)){
                res=2147483647;
                break;
              }
              else{
                res=res*10+str[count]-'0';

              }
            }
            else{
              if((res>214748364)||(res==214748364&&str[count]>8)){
                res=2147483648;
                break;
              }
              else{
                res=res*10+str[count]-'0';
              }
            }
          }
          else if(str[count]=='-'){
            flag=-1;
          }
          else if(str[count]=='+'){
            flag=1;
          }
          else if(str[count]==' '){
            if(res!=0){
              break;
            }
          }
          else{
            break;
          }

          count++;
        }
        return res*flag;

    }
};
