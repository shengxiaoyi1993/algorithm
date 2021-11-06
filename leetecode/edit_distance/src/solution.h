#include <vector>
#include <iostream>
#include <vector>

using namespace std;


//72. Edit Distance

//Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

//You have the following three operations permitted on a word:

//    Insert a character
//    Delete a character
//    Replace a character



//Example 1:

//Input: word1 = "horse", word2 = "ros"
//Output: 3
//Explanation:
//horse -> rorse (replace 'h' with 'r')
//rorse -> rose (remove 'r')
//rose -> ros (remove 'e')

//Example 2:

//Input: word1 = "intention", word2 = "execution"
//Output: 5
//Explanation:
//intention -> inention (remove 't')
//inention -> enention (replace 'i' with 'e')
//enention -> exention (replace 'n' with 'x')
//exention -> exection (replace 'n' with 'c')
//exection -> execution (insert 'u')



//Constraints:

//    0 <= word1.length, word2.length <= 500
//    word1 and word2 consist of lowercase English letters.

/// aleady known
/// 1. length
/// 2. same

/// find same letters in same seqence
/// then replace letters and insert letters
///
///
/// find all same letters  in two words
/// then


/// 使用元素递增法
/// 初始条件，若任一字符串为空，则distance，max(i,j)
/// 对于（i,j）长度的字符串，其(i-1,j)，(i,j-1),(i-1,j-1)的两字符串的变化次数已确定
///


class Solution {
public:
  int datas[501][501];


  int minDistance(string word1, string word2)
  {
    for (int i=0;i<=500;i++) {
      for (int j=0;j<=500;j++) {
        datas[i][j]=-1;
      }
    }
    return minDistance(word1,word1.size(),word2,word2.size());

  }


  int minDistance(string& word1,size_t v_size1, string& word2,size_t v_size2)
  {
    //std::cout<<"word1:"<<word1<<" "<<v_size1<<std::endl;
    //std::cout<<"word2:"<<word2<<" "<<v_size2<<std::endl;


    if (datas[v_size1][v_size2] != -1) {
      return datas[v_size1][v_size2];
    }


    int ret;

    if (min(v_size1,v_size2) == 0) {
      ret= static_cast<int>(max(v_size1,v_size2));
    }
    else
    {

      //std::cout<<"word1:"<<v_size1<<" word2:"<<v_size2<<std::endl;

      //std::cout<<"min(word1.size(),word2.size()) != 0"<<std::endl;
      int ret0=minDistance(word1,v_size1-1,word2,v_size2)+1;
      int ret1=minDistance(word1,v_size1,word2,v_size2-1)+1;
      int ret2=minDistance(word1,v_size1-1,word2,v_size2-1);
      if (word1[v_size1-1] != word2[v_size2-1]) {
        ret2+=1;
      }


      ret= min(ret0,min(ret1,ret2));

    }

    datas[v_size1][v_size2]=ret;



    return ret;


  }



};
