#include "solution.h"

int main(int argc, char const *argv[])
{
    Solution tmp;

//    string word1 = "horse", word2 = "ros";

    string word1 = "intention", word2 = "execution";



    std::cout<<"word1:"<<word1<<std::endl;
    std::cout<<"word2:"<<word2<<std::endl;


   int editdis= tmp.minDistance(word1,word2);

   std::cout<<"editdis:"<<editdis<<std::endl;

   return 0;
}
