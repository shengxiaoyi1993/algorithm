#include "solution.h"

int main(int argc, char const *argv[])
{
  Solution tmp;



  //    vector<string> words={"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
  //    int maxWidth=20;

  //    vector<string> words={"This", "is", "an", "example", "of", "text", "justification."};
  //    int maxWidth=16;

  //    vector<string> words={"What","must","be","acknowledgment","shall","be"};
  //    int maxWidth=16;


  //    vector<string> words={"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"};
  //    int maxWidth=16;

  //    ["Here","is","an","example","of","text","justification."]
  //    14

  vector<string> words={"Here","is","an","example","of","text","justification."};
  int maxWidth=14;

  vector<string> ret= tmp.fullJustify(words,maxWidth);
  for (auto it:ret) {
    std::cout<<it<<std::endl;
  }


  return 0;
}
