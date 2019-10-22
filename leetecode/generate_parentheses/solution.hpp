#include <iostream>
#include<vector>
using namespace std;
struct StringData {
  string parentheseis;
  int sum_current;
  int num_positive_left;
  int num_negtive_left;
  StringData(string str,int sum,int num_pos,int num_neg):
  parentheseis(str),
  sum_current(sum),
  num_positive_left(num_pos),
  num_negtive_left(num_neg){}

  StringData(const StringData& data):
  parentheseis(data.parentheseis),
  sum_current(data.sum_current),
  num_positive_left(data.num_positive_left),
  num_negtive_left(data.num_negtive_left){}
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
      vector<string> list_str;
      vector<StringData> list;
      StringData tmp("(",1,n-1,n);
      list.push_back(tmp);
      cout<<getString(list)<<endl;



      for(int i=0;i<list.size();i++){
        list_str.push_back(list[i].parentheseis);

      }

      return list_str;
    }



    bool getString(vector<StringData> &list){
      int listsize=list.size();

      for(int i=0;i<listsize;i++)
      {
        if(list[i].sum_current == 0)
        {
          list[i].parentheseis+="(";
          list[i].sum_current++;
          list[i].num_positive_left--;
        }
        else{
          if(list[i].num_positive_left>0){
            StringData tmp( list[i]);
            tmp.parentheseis+="(";
            tmp.sum_current++;
            tmp.num_positive_left--;
            list.push_back(tmp);
          }

          if(list[i].num_negtive_left>0){
            list[i].parentheseis+=")";
            list[i].sum_current--;
            list[i].num_negtive_left--;
          }


        }
      }

      if(list[0].num_positive_left+list[0].num_negtive_left==0){
        return true;
      }
      else{
        return getString(list);
      }

    }

};
