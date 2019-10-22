#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
      int length=digits.size();
      vector<string> list_str(length);
      vector<int> list_num(length);
      for (int i = 0; i < length; i++) {
        list_str[i]=getString(digits[i]);
        list_num[i]=list_str[i].size();
      }

      vector<string> list_str_res;
      vector<int>list_count(length);
      int flag=length;
      while (flag>0) {
        // for (size_t i = 0; i < list_count.size(); i++) {
        //   cout<<list_count[i]<<" ";
        //   /* code */
        // }
        // cout<<endl;
        list_str_res.push_back(getCombination(list_count,list_str));
        flag=addOne(list_count,list_num);
      }
      return list_str_res;
    }

    string getString(char ch){
      switch(ch){
        case '2':
          return "abc";
        case '3':
          return "def";
        case '4':
          return "ghi";
        case '5':
          return "jkl";
        case '6':
          return "mno";
        case '7':
          return "pqrs";
        case '8':
          return "tuv";
        case '9':
          return "wxyz";
        default:
          break;
      }
      return "";
    }

    int addOne(vector<int>&list_num,vector<int>list_limit){
      int length=list_num.size();
      list_num[0]++;
      for (size_t i = 0; i < length; i++) {
        if(list_num[i]>=list_limit[i]){
          list_num[i]=0;
          if(i<length){
            list_num[i+1]++;
          }
          else{
            break;
          }
        }
        else{
          return 1;
        }
      }
      return -1;
    }

    string getCombination(vector<int>list_num,vector<string>list_src){
      int length=list_num.size();
      string str_res;
      for (size_t i = 0; i < length; i++) {
        str_res+=list_src[i][list_num[i]];
      }
      return str_res;
    }

};
