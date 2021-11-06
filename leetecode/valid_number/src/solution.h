#include <vector>
#include <iostream>
#include <vector>

using namespace std;


//65. Valid Number
//A valid number can be split up into these components (in order):

//    A decimal number or an integer.
//    (Optional) An 'e' or 'E', followed by an integer.

//A decimal number can be split up into these components (in order):

//    (Optional) A sign character (either '+' or '-').
//    One of the following formats:
//        One or more digits, followed by a dot '.'.
//        One or more digits, followed by a dot '.', followed by one or more digits.
//        A dot '.', followed by one or more digits.

//An integer can be split up into these components (in order):

//    (Optional) A sign character (either '+' or '-').
//    One or more digits.

//For example, all the following are valid numbers: ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], while the following are not valid numbers: ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

//Given a string s, return true if s is a valid number.



//Example 1:

//Input: s = "0"
//Output: true

//Example 2:

//Input: s = "e"
//Output: false

//Example 3:

//Input: s = "."
//Output: false

//Example 4:

//Input: s = ".1"
//Output: true



//Constraints:

//    1 <= s.length <= 20
//    s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.

class Solution {



public:

  /// 先检查是否有e，若有分成两部分 interger/dec + interger
  /// 分别判断是否满足条件

  bool isUnsignedDecimal(const std::string & v_str)
  {
    size_t pos_find=v_str.find('.');
    if (pos_find == string::npos) {
      return false;
    }

    if (v_str.size() == 1) {
      return false;
    }

    /// no digit after '.'
    if (pos_find == v_str.size()-1) {
      return isInteger(v_str.substr(0,v_str.size()-1));
    }

    if (pos_find == 0) {

      for (size_t i=1;i<v_str.size();i++) {
        if (!isDigital(v_str[i])) {
          return false;
        }
      }
      return true;
    }

    {
      if (isInteger(v_str.substr(0,pos_find)) == false) {
        return false;
      }

      for (size_t i=pos_find+1;i<v_str.size();i++) {
        if (!isDigital(v_str[i])) {
          return false;
        }
      }
      return true;

    }

  }

  bool isDecimal(const std::string & v_str)
  {
    if (v_str.size()==0) {
      return false;
    }

    if (v_str[0]== '+' || v_str[0]== '-' ) {
      if (v_str.size() == 1) {
        return false;
      }
      else{
        return isUnsignedDecimal(v_str.substr(1,v_str.size()-1));
      }
    }
    else
    {
      return isUnsignedDecimal(v_str);
    }

  }



  bool isInteger(const std::string & v_str)
  {
    if (v_str.size()==0) {
      return false;
    }

    int start=0;
    if (v_str[0]== '+' || v_str[0]== '-' ) {
      if (v_str.size() == 1) {
        return false;
      }
      start = 1;
    }


    for (;start<v_str.size();start++) {
      if (!isDigital(v_str[start])) {
        return false;
      }
    }
    return true;

  }
  bool isDigital( char v_ch)
  {
    if (v_ch<'0'||v_ch>'9') {
      return false;
    }
    else{
      return true;
    }
  }
  bool isNumber(string s) {
    size_t pos_find;

    size_t pos_find_e=s.find('e');
    pos_find=pos_find_e;
    size_t pos_find_E=s.find('E');
    pos_find=pos_find_E!=string::npos?pos_find_E:pos_find;

    if (pos_find == string::npos) {
      return isInteger(s)||isDecimal(s);
    }
    else if ((pos_find_e != string::npos)&&(pos_find_E != string::npos)) {
      return false;
    }
    else{
      return (isInteger(s.substr(0,pos_find))||isDecimal(s.substr(0,pos_find)))
          &&isInteger(s.substr(pos_find+1,s.size()-pos_find));
    }

    }

};
