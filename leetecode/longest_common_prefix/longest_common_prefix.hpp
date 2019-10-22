#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count_string=strs.size();
        int count=0;
        if(count_string > 0){
          count=strs[0].size();
        }
        else{
          return "";
        }

        for(int i=0;i<count_string-1;i++){
          int length_tmp=lengthOfCommonPrefix(strs[i],strs[i+1],count);
          cout<<"length_tmp:"<<length_tmp<<endl;
          if(length_tmp == 0){
            return "";
          }
          else{
              count = length_tmp;
          }



        }
       cout<<"count:"<<count<<endl;


        return  strs[0].substr(0,count);

    }

    int lengthOfCommonPrefix(string str1,string str2,int num){

      int size_1=str1.size();
      int size_2=str2.size();
      int size=size_1<size_2?size_1:size_2;
      int value=0;


      for(int i=0;i<size;i++){
        if(str1[i] == str2[i]){
          value=i+1;
          if(value>=num){
            break;
          }
        }
        else{
          break;
        }
      }
      return value;
    }
};
