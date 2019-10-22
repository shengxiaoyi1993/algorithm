#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
      int num_in=num;
        if(num>3999||num<1){
          return "";
        }

        string str_res="";

        if (num_in>=1000) {
          int num_tmp=num_in/1000;
          num_in  %=1000;
          for(int i=0;i<num_tmp;i++){
            str_res+="M";
          }
        }
        // cout<<"str_res:"<<str_res<<endl;

        if(num_in>=100){
          int num_tmp=num_in/100;

          num_in%=100;
          if(num_tmp>=5&&num_tmp<9){
            str_res+="D";
            for(int i=0;i<(num_tmp-5);i++){
              str_res+="C";
            }
            // cout<<"1"<<endl;
          }
          else if(num_tmp==9){
            str_res+="CM";

          }
          else if(num_tmp==4){
            str_res+="CD";

          }
          else{
            for(int i=0;i<num_tmp;i++){
              str_res+="C";
            }
          }
        }

        // cout<<"str_res:"<<str_res<<endl;

        if(num_in>=10){
          int num_tmp=num_in/10;
          num_in%=10;
          if(num_tmp>=5&&num_tmp<9){
            str_res+="L";
            for(int i=0;i<(num_tmp-5);i++){
              str_res+="X";
            }
          }
          else if(num_tmp==9){
            str_res+="XC";

          }
          else if(num_tmp==4){
            str_res+="XL";

          }
          else{
            for(int i=0;i<num_tmp;i++){
              str_res+="X";
            }
          }
        }

        if(num_in>=1){
          int num_tmp=num_in/1;

          num_in%=1;
          if(num_tmp>=5&&num_tmp<9){
            str_res+="V";
            for(int i=0;i<(num_tmp-5);i++){
              str_res+="I";
            }
          }
          else if(num_tmp==9){
            str_res+="IX";

          }
          else if(num_tmp==4){
            str_res+="IV";

          }
          else{
            for(int i=0;i<num_tmp;i++){
              str_res+="I";
            }
          }
        }
        return str_res;

    }
};
