//
// 43. Multiply Strings
//
// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//
// Example 1:
//
// Input: num1 = "2", num2 = "3"
// Output: "6"
//
// Example 2:
//
// Input: num1 = "123", num2 = "456"
// Output: "56088"
//
// Note:
//
//     The length of both num1 and num2 is < 110.
//     Both num1 and num2 contain only digits 0-9.
//     Both num1 and num2 do not contain any leading zero, except the number 0 itself.
//     You must not use any built-in BigInteger library or convert the inputs to integer directly.
//

//1. 取某个数的各个位的数值与另一个数相乘后相加（暴力迭代）
// 递归函数 输入两个字符串 输出乘积
//若num1_size<1,输出null
//若num1_size==1,
//  若num2_size==0,输出null
//  若num2_size==1,计算字符串乘积
//  若num2_size>1,分离第一个字符与后续字符；将后续字符串使用迭代函数进行计算得到结果；与之前的数据相加
//若num1_size>1,则num1 去除第一个字符进行迭代计算；然后进行相加


//2. 从原理出发
//定义结果sum=0
//逐个计算，各个位数的相乘i,j的结果，sum+=tmp*10^(num1_size-i+num2_size-j)
//将sum转换成字符串
//[结果]：超出范围

//3. 定义矩阵
//横坐标为num2中的，纵坐标为num1的点
//定义一个数来保存进位
//所有横纵坐标之和为tmpsum（0->size1+size2-1）的数与进位相加，得到当前位的字符串，和新的进位数，
//查看余下的进位数，若不为零则将进位数添加到字符串中
#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
  string numToString(int v_num){
    string list;
     do{
      list.insert(list.begin(),(char)(v_num%10+'0'));
      v_num=v_num/10;
    }while (v_num!=0);
    return list;

  }


  string multiply(string num1, string num2) {
    int num1_size=num1.size();
    int num2_size=num2.size();
    int num1_size_1=num1_size-1;
    int num2_size_1=num2_size-1;
    int mat[num1_size][num2_size];


    int sum=0;
    for (size_t i = 0; i < num1_size; i++) {
      for (size_t j = 0; j < num2_size; j++) {
        mat[i][j]=(num2[num2_size_1-j]-'0')*(num1[num1_size_1-i]-'0');
      }
    }

    string  ret;
    int ret_size=num1_size+num2_size;
    int ret_size_1=ret_size-1;
    ret.resize(ret_size);
    int carry=0;
    for (size_t tmpsum = 0; tmpsum < ret_size; tmpsum++) {
      int tmp=carry;
      for (size_t i = 0; i<num1_size; i++) {
        if (tmpsum-i < num2_size) {
          tmp+=mat[i][tmpsum-i];
        }
      }
      ret[ret_size_1-tmpsum]=tmp%10+'0';
      carry=tmp/10;
    }


    if(carry>0){
      string tmpstr=numToString(carry);
      ret=ret.insert(0,tmpstr);
    }

    int count_zero=0;
    while (ret[count_zero]=='0'&&count_zero<ret.size()-1) {
      count_zero++;
    }
      ret.erase(ret.begin(),ret.begin()+count_zero);
    return ret;


  }

};
