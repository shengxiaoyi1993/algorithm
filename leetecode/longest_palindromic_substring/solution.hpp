#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
  bool isPalindrome(string s){
    if(s.size()==0){
      return false;
    }
    for(int i=0;i<s.size()/2;i++){
      if(s[i]!=s[s.size()-1-i]){
        return false;
      }
    }
    return true;
  }
    string longestPalindrome(string s) {
      int start=0;
      int length=0;
      for(int i=0;i<s.size();i++){
        for(int j=s.size()-1;j>=i;j--){
          if(s[j]==s[i]){
            if(isPalindrome(s.substr(i,j-i+1))){
              if(length<j-i+1){
                start = i;
                length=j-i+1;
              }
              break;
            }
          }
        }
      }
      return s.substr(start,length);
    }



};
// string longestPalindrome(string s) {
//   int left=0;
//   int len=1;
//   for(int i=0;i<s.size();i++){
//     int distance=0;
//     string str_tmp=s.substr(i-distance,distance*2+1);
//     while(isPalindrome(str_tmp)){
//       if(len<distance*2+1){
//         left=i-distance;
//         len=distance*2+1;
//       }
//
//       distance++;
//       if(i-distance>=0&&i+distance<s.size()){
//         str_tmp=s.substr(i-distance,distance*2+1);
//       }
//       else{
//         break;
//       }
//
//     }
//
//     int singlelen=1;
//     string str_tmp2=s.substr(i-singlelen+1,singlelen*2);
//     while(isPalindrome(str_tmp2)){
//       if(len<singlelen*2){
//         left=i-singlelen+1;
//         len=singlelen*2;
//       }
//       singlelen++;
//
//       if(i-singlelen+1>=0&&i+singlelen<s.size()){
//         str_tmp2=s.substr(i-singlelen+1,singlelen*2);
//       }
//       else{
//         break;
//       }
//     }
//   }
//   return s.substr(left,len);
// }
