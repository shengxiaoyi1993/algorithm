#include<iostream>
#include<string>
using namespace std;
class Solution {
    public:
string convert(string s, int numRows) {
      int flag=0;
      int len=s.size();
      char array_trans[numRows][len];
      for(int i=0;i<numRows;i++){
        for(int j=0;j<len;j++){
          array_trans[i][j]=0;
          // cout<<" "<<(int)array_trans[i][j];
          // res_s+=array_trans[i][j];
        }
        // cout<<endl;
      }
      int i=0;
      int j=0;
      flag=1;
      array_trans[0][0]=s[0];
      for(int count=1;count<len;count++){
        if(flag<numRows){
          i++;
          array_trans[i][j]=s[count];
        }
        else {
          i--;
          j++;
          array_trans[i][j]=s[count];

        }

        flag++;
        if(flag==2*numRows-1){
          flag=1;
        }
        // cout<<" "<<count<<":"<<s[count]<<endl;
      }
      string res_s="";
      for(int i=0;i<numRows;i++){
        for(int j=0;j<len;j++){
          // cout<<" "<<(int)array_trans[i][j];
          if(array_trans[i][j]>0){
            res_s+=array_trans[i][j];

          }
        }
        // cout<<endl;
      }
      return res_s;
    }
};


// string str="";
// int len=s.length();
// if(numRows==1)
//     return s;
// else
// {
//  int i=0;
// int x=0;
// int y=0;
// int flag=0;
// char ch[][]=new char[len][numRows];
// while(i<len)
// {
//   while(y<numRows&&flag==0&&i<len)
//   {
//
//   ch[x][y]=s.charAt(i);
//   i++;
//   y++;
//   }
//   flag=1;
//   y--;
//
//   while(y>0&&flag==1&&i<len)
//   {
//   x++;
//   y--;
//
//   ch[x][y]=s.charAt(i);
//   i++;
//   }
//   y++;
//   flag=0;
// }
//
// for(int j=0;j<numRows;j++)
// {
// for(int k=0;k<len;k++)
// {
//   if(ch[k][j]>0)
//   str=str+string.valueOf(ch[k][j]);
//
// }
// }
// return 	str;
// }
