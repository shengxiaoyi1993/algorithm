//
// 44. Wildcard Matching
//
// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
//
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
//
// The matching should cover the entire input string (not partial).
//
// Note:
//
//     s could be empty and contains only lowercase letters a-z.
//     p could be empty and contains only lowercase letters a-z, and characters like ? or *.
//
// Example 1:
//
// Input:
// s = "aa"
// p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
//
// Example 2:
//
// Input:
// s = "aa"
// p = "*"
// Output: true
// Explanation: '*' matches any sequence.
//
// Example 3:
//
// Input:
// s = "cb"
// p = "?a"
// Output: false
// Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
//
// Example 4:
//
// Input:
// s = "adceb"
// p = "*a*b"
// Output: true
// Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
//
// Example 5:
//
// Input:
// s = "acdcb"
// p = "a*c?b"
// Output: false
//

//思路
//迭代法
//将连在一起的‘*’转换成1个
//对于p中的第一个字符
//  若字符为*,
//     包含s中0个，1个..., 去除p中的*和s中的若干字符,分别进行迭代计算，
//        若含有一个匹配为真，则返回真；
//        否则返回false
//  若字符为.，去除p首个字符与s的首个字符，进行迭代算，返回
//  若字符为a-z,
//    若匹配，则去除p首个字符与s的首个字符，进行迭代算，结果
//    若不匹配，返回false


// 动态规划，定义dp[i][j]为s[:i] 与p[:j]是否匹配。
// 状态转移如下：
//
//     如果p[j]不是*，那么p[j]就只能配一个字符，状态转移为dp[i][j] = dp[i-1][j-1] && (s[i] == p[j] || p[j] == '?')
//     如果p[j]是*， 那么说明p[j]可以配0到任意多字符。再分为两类：
//         如果匹配0个字符，那么就是dp[i][j-1]
//         如果匹配大于等于1个字符，那么可以把s[i]看做直接去掉，看s[:i-1]与p[:j]是否匹配即可。(无穷多个，拿掉几个无所谓) dp[i-1][j]
//         综上，dp[i][j] = dp[i-1][j] || dp[i][j-1]

//实际算法
//以（0，0）作为算法的起始点，即两个空字符串，匹配
//dp[sz+1][pz+1]
//各自在字符串末尾添加字符
//  p添加?或者[a-z],匹配一个字符
//  p添加*，匹配[0～n]个字符，即dp[j~sz][i]的值均为dp[n-1][i-1]

//最后的结果由dp[sz][pz]确定


// bool isMatch(string s, string p) {
//     int n = s.size(), m = p.size();
//     s = " " + s;
//     p = " " + p;
//     vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
//     dp[0][0] = true;
//     for (int i = 1; i <= m; i ++) {
//         if (p[i] == '*') dp[0][i] = dp[0][i-1];
//     }
//     for (int j = 1; j <= m; j ++) {
//         for (int i = 1; i <= n; i ++) {
//             if (p[j] != '*') dp[i][j] = dp[i-1][j-1] && (s[i] == p[j] || p[j] == '?');
//             else dp[i][j] = dp[i-1][j] || dp[i][j-1];
//         }
//     }
//     return dp[n][m];
// }
//需要保证能够迭代到所有情况
//对于某一"*"字符，与当前字符的关系，此时s[i]定不属于p[j-1]
//  匹配当前字符    return v[i-1][j-1]
//  不包含的当前字符 return return v[i][j-1]



//对于dp[i][j],只需要考虑s,p此时是否匹配就行了，不用考虑多一个字符之后的情况
//faq
//  当


#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Solution {
  public:
    bool isMatch(string s, string p) {
      int n = s.size(), m = p.size();
      vector<vector<bool> > dp(n + 1, vector<bool>(m + 1, false));
      s=" "+s;
      p=" "+p;
      //对于p为""
      dp[0][0]=true;
      //对于s为空
      for (size_t i = 1; i <= m; i++) {
        if(p[i]=='*'){
          dp[0][i]=dp[0][i-1];
        }
      }

      //对于边缘部分已经设置
      //借助前一点的状态，判断当前点的状态，即dp[i-1][j-1],dp[i-1][j],dp[i][j-1]的状态已经确定
      for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {

          if(p[j] != '*'){
            dp[i][j]=dp[i-1][j-1]&&((p[j]=='?')||(s[i]==p[j]));
          }
          else{
            dp[i][j]=dp[i-1][j-1]||dp[i][j-1]||dp[i-1][j];
          }
          // std::cout <<"i: "<<i<<" j: "<<j<<" "<< dp[i][j] <<' '<<endl;
        }
        // std::cout  << '\n';
      }
      // std::cout  << '\n';
      return dp[n][m];
    }
};


//
// class Solution {
// public:
//   vector<vector<int> > g_record;
//   bool isMatchBase(string s, string p) {
//     // std::cout << "test1" << '\n';
//     // std::cout << "s:"<<s << '\n';
//     // std::cout << "p:"<<p << '\n';
//     for (size_t i = 0; i < g_record.size(); i++) {
//       for (size_t j = 0; j < g_record[i].size(); j++) {
//         std::cout <<setw(2)<<g_record[i][j] <<" " ;
//
//       }
//       std::cout << "" << '\n';
//       /* code */
//     }
//     std::cout << "" << '\n';
//
//
//
//     int s_size=s.size();
//     int p_size=p.size();
//
//     if(g_record[s_size][p_size]>=0){
//       return g_record[s_size][p_size];
//     }
//
//     bool ret;
//
//     if(s.size()==0&&p.size()==0){
//       ret= true;
//     }
//     else if(s.size()==0&&(p[0]!='*')){
//       ret= false;
//     }
//     else{
//
//           switch (p[0]) {
//             case '*':{
//               p.erase(p.begin());
//               while (true) {
//                 if(isMatchBase(s,p)){
//                   ret= true;
//                 }
//                 if(s.size()==0){
//                   break;
//                 }
//                 s.erase(s.begin());
//               }
//               ret= false;
//             }
//             break;
//             case '?':{
//               p.erase(p.begin());
//               s.erase(s.begin());
//               ret= isMatchBase(s,p);
//             }
//             break;
//             default :{
//               if(p[0]==s[0]){
//                 p.erase(p.begin());
//                 s.erase(s.begin());
//                 ret= isMatchBase(s,p);
//               }
//               else{
//                 ret= false;
//               }
//             }
//           }
//     }
//
//     g_record[s_size][p_size]=ret;
//     return ret;
//   }
//
//     bool isMatch(string s, string p) {
//       g_record.resize(s.size()+1);
//       for (size_t i = 0; i < g_record.size(); i++) {
//         g_record[i].resize(p.size()+1);
//         for (size_t j = 0; j < g_record[i].size(); j++) {
//           g_record[i][j]=-1;
//         }
//       }
//       if(p.size()>1){
//         int count=0;
//         //前一个字符是否为'*'
//         bool flag=false;
//         while (count<p.size()) {
//           if(p[count] == '*'){
//             if(flag){
//               p.erase(p.begin()+count);
//             }
//             else{
//               count++;
//             }
//             flag=true;
//           }
//           else{
//             flag=false;
//             count++;
//           }
//         }
//       }
//       // std::cout << "p:"<<p << '\n';
//
//
//       return isMatchBase(s,p);
//     }
//
// };
