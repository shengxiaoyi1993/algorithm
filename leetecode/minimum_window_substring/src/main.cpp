#include "solution.h"

int main(int argc, char const *argv[])
{
    Solution tmp;


    string s="ADOBECODEBANC";
    string t="ABC";

//    string s="a";
//    string t="a";

//    string s="a";
//    string t="aa";



    string ret=tmp.minWindow(s,t);
    cout<<"ret:"<<ret<<endl;

    
    return 0;
}
