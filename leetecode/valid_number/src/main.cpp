#include "solution.h"

int main(int argc, char const *argv[])
{
  Solution tmp;

//  string s = "0";

//  string s = "e";

//  string s = ".";

//  string s = ".1";

//  string s = "-0.1";

//  string s = "-0.";
  string s = "-.2";


  bool ret= tmp.isNumber(s);
  std::cout<<"ret:"<<ret;

  return 0;
}
