#include "solution.h"

int main(int argc, char const *argv[])
{
    Solution tmp;


//    string input="/../";
//    string input="/home//foo/";
//    string input="/a/./b/../../c/";
        string input="/a//b////c/d//././/..";



    string ret=tmp.simplifyPath(input);
    std::cout<<"ret:"<<ret<<std::endl;



    
    return 0;
}

