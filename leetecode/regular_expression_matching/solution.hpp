#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
      typedef struct CharAndInt{
        char ch;
        int num;
      }CharAndInt;

      int count_s=0;
      int count_s_l=0;
      char tmp_ch_s='0';

      CharAndInt list_s[s.size()];
      CharAndInt list_p[s.size()];

      while(count_s<s.size()){
        if(list_s[count_s_l].ch<=0){
          list_s[count_s_l].ch=s[count_s];
          list_s[count_s_l].num++;
          tmp_ch_s=s[count_s];
          count_s++;
          continue;
        }
        else{
          if(s[count_s]==tmp_ch_s){
            list_s[count_s_l].num++;
          }
          else{
            count_s_l++;
            list_s[count_s_l].ch=s[count_s];
            list_s[count_s_l].num++;
            tmp_ch_s=s[count_s];
          }
          count_s++;
        }

      }

      int count_p=0;
      int count_p_l=0;
      char tmp_ch_p='0';
      while(count_p<p.size()){
        if(list_p[count_s_l].ch<=0){
          list_p[count_s_l].ch=s[count_s];
          list_p[count_s_l].num++;
          tmp_ch_s=s[count_s];
          count_s++;
          continue;
        }

        if(p[count_p]=='.'){
          count_s_l++;
          list_p[count_s_l].ch=s[count_s];
          list_p[count_s_l].num++;
          tmp_ch_s=s[count_s];
        }
        else if(p[count_p]=='*'){
          if(tmp_ch_p=='*'){
            continue;
          }
          list_p[count_s_l].num=-1;

        }
        else if(p[count_p]>='a'&&p[count_p]<='z'){
          if(s[count_s]==tmp_ch_s){
            if(list_p[count_s_l].num!=-1){
              list_p[count_s_l].num++;
            }
          }
          else{
            count_s_l++;
            list_p[count_s_l].ch=s[count_s];
            list_p[count_s_l].num++;
            tmp_ch_s=s[count_s];
          }
        }
        count_s++;

      }



      for(int i=0;i<=count_p_l;i++){
        cout<<"ch: "<<list_p[i].ch<<"num: "<<list_p[i].num<<endl;
      }
      return true;
    }
};
