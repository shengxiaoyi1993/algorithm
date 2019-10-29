#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
      std::vector<int> list_position;

      std::vector<int> list_help;
      if(words.size()==0||s.size()==0){
        return list_help;
      }

      for(int i=0;i<words.size();i++){
        list_help.push_back(0);
      }

      int size=s.size();
      int size_short=words[0].size();
      int size_div=size-size_short*words.size();
      // cout<<"size_div:"<<size_div<<endl;
      for (int i = 0; i <= size_div; i++) {
        // cout<<"run:"<<i<<endl;

        //match all word for init-string and its sub-string
        int count_match=0;
        while (!isMatchHeadInList(s.substr(i+count_match*size_short,size-i-count_match*size_short),
        words,list_help)) {
          count_match++;
          /* code */
        }
        if(isAllMatched(list_help)){
          list_position.push_back(i);
        }
        for (size_t j = 0; j < list_help.size(); j++) {
          list_help[j]=0;
          /* code */
        }
      }
        // list_position.push_back(0);
        return list_position;
    }


    bool isMatchHead(string str_long ,string str_short){
      int size_long =str_long.size();
      int size_short=str_short.size();
      if(str_short>str_long){
        return false;
      }
      for(int i=0;i<str_short.size();i++){
        if(str_long[i] != str_short[i]){
          return false;
        }
      }
      return true;
    }

    //returm if match is ended
    bool isMatchHeadInList(
      string str_long,
      std::vector<string> words,
      std::vector<int>& list_help){
        int size_words=words.size();
        bool flag=true;
        //map all in words
        //no condition that all list_help is 1
        //when cannot find, return true
        //when find ,but result after change not all 1, false
         //         result after change all equal 1, true
      for (size_t i = 0; i < size_words; i++) {
        //alway one exist
        if(list_help[i] == 0){
          if(isMatchHead(str_long,words[i])){
            list_help[i]=1;
            //match ,if all in list_help equal 1,stop,return true
            //       else not all in list_help equal  1,means need next match,return false
            if(isAllMatched(list_help)){
              return true;
            }
            else{
              return false;
            }
          }
          else{
            continue;
            //not match ,need test next if there is one remain,continue
            //           return true if there is none remain,stop
          }
        }
      }
      return flag;
    }


    bool isAllMatched(std::vector<int> list_help){
      for (size_t i = 0; i < list_help.size(); i++) {
        if(list_help[i]!=1){
          return false;
        }
      }
      return true;
    }
};
