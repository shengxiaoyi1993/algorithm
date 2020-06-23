#include <iostream>
#include <stack>
using namespace std;

// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
// Example 1:
//
// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"
//
// Example 2:
//
// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"
//


//假设
//使用栈来解决这个问题

//逐个遍历字符
//  若字符为（，压入栈
//      若start为-1，则start置为当前数值
//  若字符为），查看栈
//     若栈为空
//        重置start为-1 //不连续状态
//     若栈不为空，取出栈顶元素，判断之后的队列是否为空
//        若start为-1，则start置为当前数值，此时该段定为2
//        为空：需要用到start数据计算，i-v_start+1;
//        不为空：使用取出栈顶元素后的栈顶值进行计算，i-vstack.top();
//



class Solution {
public:
    int longestValidParentheses(string s) {
      stack<int> vstack;
      int v_max=0;
      int v_start=0;
      int v_length=s.size();
      for(int i=0;i<v_length;i++){
        if(s[i] == '('){
          vstack.push(i);
          if(v_start == -1){
            v_start=vstack.top();
          }
        }
        else{
          if(!vstack.empty()){

            if(v_start == -1){
              v_start=vstack.top();
            }
            vstack.pop();
            if(!vstack.empty()){
              int tmp=i-vstack.top();
              v_max=v_max>tmp?v_max:tmp;
            }
            else{
              int tmp=i-v_start+1;
              v_max=v_max>tmp?v_max:tmp;
            }

          }
          else{
            v_start=-1;
          }
        }
      }//end of read characters

      return v_max;
    }
};
