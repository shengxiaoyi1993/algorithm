#include "solution.h"

int main(int argc, char const *argv[])
{
  Solution tmp;


  int n=3;
  int k=1;

//  int n=3;
//  int k=3;

//  char *p=NULL;
//  free(p);
//  p=NULL;

//  int n=4;
//  int k=9;

//  int n=9;
//  int k=9;

  string str=tmp.getPermutation(n,k);
  std::cout<<"("<<n<<
             ","<<k<<
             "):"<<str<<std::endl;

//  k= n+n-1 + n-2 + ... +i

//  string str=tmp.getPermutation(n,k);


  return 0;
}

//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.



//Example 1:

//Input: n = 3
//Output: [[1,2,3],[8,9,4],[7,6,5]]

//Example 2:

//Input: n = 1
//Output: [[1]]



//Constraints:

//    1 <= n <= 20



//61. Rotate List

//Given the head of a linked list, rotate the list to the right by k places.



//Example 1:

//Input: head = [1,2,3,4,5], k = 2
//Output: [4,5,1,2,3]

//Example 2:

//Input: head = [0,1,2], k = 4
//Output: [2,0,1]



//Constraints:

//    The number of nodes in the list is in the range [0, 500].
//    -100 <= Node.val <= 100
//    0 <= k <= 2 * 109

