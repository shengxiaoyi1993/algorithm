#include <iostream>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
      string tmp_str;
        char a_ch;
        char b_ch;
        char h_ch='0';
        int maxsize=(a.size()>b.size())?a.size():b.size();
        // cout<<"maxsize:"<<maxsize<<endl;

        for(int a_count=a.size()-1, b_count=b.size()-1,i=maxsize-1;
                i>=0;i--,a_count--,b_count--){
                  // cout<<"i:"<<i<<endl;

            if(a_count>=0&&b_count>=0){
              if(CountNumber(a[a_count],b[b_count],h_ch)==3){
                tmp_str="1"+tmp_str;
                h_ch='1';
              }
              else if(CountNumber(a[a_count],b[b_count],h_ch)==2){
                tmp_str="0"+tmp_str;
                h_ch='1';
              }
              else if(CountNumber(a[a_count],b[b_count],h_ch)==1){
                tmp_str="1"+tmp_str;
                h_ch='0';
              }
              else{
                tmp_str="0"+tmp_str;
                h_ch='0';
              }
            }
            else if(a_count<0){
              if(CountNumber('0',b[b_count],h_ch)==3){
                tmp_str="1"+tmp_str;
                h_ch='1';
              }
              else if(CountNumber('0',b[b_count],h_ch)==2){
                tmp_str="0"+tmp_str;
                h_ch='1';
              }
              else if(CountNumber('0',b[b_count],h_ch)==1){
                tmp_str="1"+tmp_str;
                h_ch='0';
              }
              else{
                tmp_str="0"+tmp_str;
                h_ch='0';
              }
            }
            else{
                if(CountNumber(a[a_count],'0',h_ch)==3){
                  tmp_str="1"+tmp_str;
                  h_ch='1';
                }
                else if(CountNumber(a[a_count],'0',h_ch)==2){
                  tmp_str="0"+tmp_str;
                  h_ch='1';
                }
                else if(CountNumber(a[a_count],'0',h_ch)==1){
                  tmp_str="1"+tmp_str;
                  h_ch='0';
                }
                else{
                  tmp_str="0"+tmp_str;
                  h_ch='0';
                }
        }
        // cout<<"string:"<<tmp_str<<endl;
    }
    if(h_ch=='1'){
      tmp_str="1"+tmp_str;
    }
    return tmp_str;

  }
    int CountNumber(char a,char b,char c){
      int count=0;
      if(a=='1'){
        count++;
      }
      if(b=='1'){
        count++;
      }
      if(c=='1'){
        count++;
      }
      return count;
    }
};
