#include <vector>
#include <iostream>
#include <vector>


using namespace std;


//68. Text Justification

//Given an array of strings words and a width maxWidth, format the text such
//that each line has exactly maxWidth characters and is fully (left and right) justified.

//You should pack your words in a greedy approach; that is, pack as many words
//as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

//Extra spaces between words should be distributed as evenly as possible.
//If the number of spaces on a line does not divide evenly between words,
//the empty slots on the left will be assigned more spaces than the slots on the right.

//For the last line of text, it should be left-justified and no extra space is inserted between words.

//Note:

//    A word is defined as a character sequence consisting of non-space characters only.
//    Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
//    The input array words contains at least one word.



//Example 1:

//Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
//Output:
//[
//   "This    is    an",
//   "example  of text",
//   "justification.  "
//]

//Example 2:

//Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
//Output:
//[
//  "What   must   be",
//  "acknowledgment  ",
//  "shall be        "
//]
//Explanation: Note that the last line is "shall be    " instead of "shall     be",
//because the last line must be left-justified instead of fully-justified.
//Note that the second line is also left-justified becase it contains only one word.

//Example 3:

//Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
//Output:
//[
//  "Science  is  what we",
//  "understand      well",
//  "enough to explain to",
//  "a  computer.  Art is",
//  "everything  else  we",
//  "do                  "
//]



//Constraints:

//    1 <= words.length <= 300
//    1 <= words[i].length <= 20
//    words[i] consists of only English letters and symbols.
//    1 <= maxWidth <= 100
//    words[i].length <= maxWidth


/// try to insert one word every time
/// convert to next line when total length of words+ n_words-1 will larger than max_length
///
/// process
/// set up a line ,(n_w=0,length=0)
///try to add word .then p_length  p_length+p_n_w-1
/// > if p_length>max_length,not insert ,continue to setup a new line
/// > if p_length<=max_length,insert it ,and if p_lengt==max_length ,continue
/// handle all num
///
/// try convert to pure math caculation
class Solution {
public:

  string combine(const vector<string>& words,int v_start,int v_length,int v_wordlength, int maxWidth)
  {
    if (v_length == 1) {
      return words[v_start]+string(maxWidth-v_wordlength,' ');
    }

    string ret;
    int space_base=(maxWidth-v_wordlength)/(v_length-1);
    int num_morespace=(maxWidth-v_wordlength)%(v_length-1);
    for (int i=0;i<v_length;i++) {
      if (i == v_length-1) {
        ret+=words[v_start+i];
      }
      else if (i<num_morespace) {//space_base+1
        ret+=words[v_start+i];
//        for (int j=0;j<num_morespace+1;j++) {
//          ret+=' ';
//        }

        ret+=string(space_base+1,' ');

      }
      else
      {
        ret+=words[v_start+i];
//        for (int j=0;j<num_morespace;j++) {
//          ret+=' ';
//        }
        ret+=string(space_base,' ');

      }

    }
    return ret;
  }

  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> l_ret;

    int length_word_line=0;
    int num_word_record=0;
    int num_word=0;
    for (auto it:words) {
      if (length_word_line+num_word+it.length()>maxWidth) {
      l_ret.push_back( combine(words,num_word_record,num_word,length_word_line,maxWidth));
      length_word_line=it.length();
      num_word_record+=num_word;
      num_word=1;

      }
      else{
        length_word_line+=it.length();
        num_word++;

        if (length_word_line+num_word-1==maxWidth) {
          l_ret.push_back( combine(words,num_word_record,num_word,length_word_line,maxWidth));
          length_word_line=0;
          num_word_record+=num_word;
          num_word=0;
        }

      }
    }

    //handle last line,must
    if (num_word != 0) {
      string tmp;
      for(int i=num_word_record;i<words.size()-1;i++)
      {
        tmp+=(words[i]+string(1,' '));
      }
      tmp+=words[words.size()-1];


      tmp+=string((maxWidth-tmp.length()),' ');
      l_ret.push_back(tmp);

    }


    return l_ret;

  }

};
