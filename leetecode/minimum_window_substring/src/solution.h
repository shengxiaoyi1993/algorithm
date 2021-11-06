#include <vector>
#include <iostream>
#include <map>


using namespace std;



//76. Minimum Window Substring

//Given two strings s and t of lengths m and n respectively, return the minimum window
//substring of s such that every character in t (including duplicates) is included in the window.
//If there is no such substring, return the empty string "".

//The testcases will be generated such that the answer is unique.

//A substring is a contiguous sequence of characters within the string.



//Example 1:

//Input: s = "ADOBECODEBANC", t = "ABC"
//Output: "BANC"
//Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

//Example 2:

//Input: s = "a", t = "a"
//Output: "a"
//Explanation: The entire string s is the minimum window.

//Example 3:

//Input: s = "a", t = "aa"
//Output: ""
//Explanation: Both 'a's from t must be included in the window.
//Since the largest window of s only has one 'a', return empty string.



//Constraints:

//    m == s.length
//    n == t.length
//    1 <= m, n <= 105
//    s and t consist of uppercase and lowercase English letters.


//Follow up: Could you find an algorithm that runs in O(m + n) time?


/// 找到s中的最小子串，使子串包含t中的所有字符
///
/// 1
/// 逐个列出子串，检查是否满足条件
/// 用移动窗口方法进行逐个遍历 (m,n)
/// 子串的最小长度为size_t
/// - 子串与t比较
/// ... 满足
///  - m++,是否已有，有则进行长度比较，选择短的暂存（若子串与t同长度，则直接返回），continue
/// ... 不满足，n++，continue
/// 检查暂存的字符串，进行输出
class Solution {
public:
  /// 是否包含的算法
  /// 只对关注的字符串进行计数

  bool isAllZeroOrLower(const map<char,int> & m_c)
  {

    for (auto it:m_c) {
      if (it.second>0) {
        return false;
      }
    }
    return true;
  }


    string minWindow(string s, string t) {
      size_t m=0,n=t.size()-1;

      string substr="";

      /// 子字符串有两种前进方式，头前进或尾前进
      bool isHeadMove;
      map<char,int> map_t;
      for (auto it:t) {
        map_t[it]++;
      }

      ///当比较时，sub_s 中的每个字符使相应的计数减一
      /// 当根据是否所有的计数<=0可以判断，字符串是否匹配

      /// 这里的标识字符串采用动态变化式，在同一个标识字符串上增减
      if (s.size()<t.size()) {
        return substr;
      }
      else{
        for(size_t i=m;i<=n;i++){
          if (map_t.find(s[i]) != map_t.end()) {
            map_t[s[i]]--;
          }
        }
        if (isAllZeroOrLower(map_t)) {
          substr=s.substr(m,n-m+1);
          if (substr.size() == t.size()) {
            return substr;
          }
        }
        isHeadMove=false;
        n++;
      }


      /// 运行到此，前子字符串不匹配

      while (m<=n&&n<s.size())
      {

//        cout<<m<<" "<<n<<endl;


        if (isHeadMove) {

          if (map_t.find(s[m-1]) != map_t.end()) {
            map_t[s[m-1]]++;
          }
          if (isAllZeroOrLower(map_t)) {
            if (substr.empty()||substr.size()>n-m+1) {
              substr=s.substr(m,n-m+1);
              if (substr.size() == t.size()) {
                return substr;
              }
            }
            m++;
            isHeadMove=true;

          }
          else{
            n++;
            isHeadMove=false;
          }

        }
        else
        {
          if (map_t.find(s[n]) != map_t.end()) {
            map_t[s[n]]--;

            if (isAllZeroOrLower(map_t)) {
              if (substr.empty()||substr.size()>n-m+1) {
                substr=s.substr(m,n-m+1);
                if (substr.size() == t.size()) {
                  return substr;
                }
              }
              m++;
              isHeadMove=true;
              continue;

            }

          }
          n++;
          isHeadMove=false;

        }

      }

      return substr;
    }
};
