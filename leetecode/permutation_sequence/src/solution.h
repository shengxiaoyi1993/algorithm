#include <vector>
#include <iostream>
#include <vector>

using namespace std;


//60. Permutation Sequence

//The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

//By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

//    "123"
//    "132"
//    "213"
//    "231"
//    "312"
//    "321"

//Given n and k, return the kth permutation sequence.



//Example 1:

//Input: n = 3, k = 3
//Output: "213"

//Example 2:

//Input: n = 4, k = 9
//Output: "2314"

//Example 3:

//Input: n = 3, k = 1
//Output: "123"



//Constraints:

//    1 <= n <= 9
//    1 <= k <= n!

/// sort the permutations and


/// set solid position S
/// before and include this position,is solid,
/// and sort the num after the  S,

/// sub issue is
/// given how to get permutaion list as the number rise
/// s

class Solution {
public:
    // static constexpr array l_num {1,2,6,24,120,720,5040,40320,362880};
// static const vector<int> l_num={1,2,6,24,120,720,5040,40320,362880};
  string getPermutation(int n, int k)
  {

    vector<int> l_num(n+1,1);
    for (int i=1;i<=n;i++) {
      l_num[i]=l_num[i-1]*(i);
    }

//    std::cout<<"l_num:"<<endl;
//    for (auto ij:l_num) {
//      std::cout<<ij<<" ";
//    }
//    std::cout<<endl;


    /// the point to the position of permutaion k
//    vector<int> l_seq(n+1,0);

    k--;

//    vector<int> l_ret(n,0);
    vector<int> l_ele(n+1,1);

    string str_ret;

    for (int i=0;i<n;i++) {
      int order=k/l_num[n-i-1]+1;
//            std::cout<<v_seq<<" ";

      k=k%l_num[n-i-1];
//      int order=v_seq+1;

      for (int j=1;j<=n;j++) {
        order-=l_ele[j];
        if (!order) {
          str_ret+=(j+'0');
          l_ele[j]=0;
          break;
        }
      }

    }
//    l_seq[n]=0;

//    std::cout<<"l_seq:"<<endl;
//    for (auto ij:l_seq) {
//      std::cout<<ij<<" ";
//    }
//    std::cout<<endl;

//    vector<int> l_ele(n,0);
//    for (int i=0;i<n;i++) {
//      l_ele[i]=1+i;
//    }

//    vector<int> l_ele(n+1,1);


//    /// 逐个取值
////    vector<int> l_ret(n,0);
//    for (int i=0;i<n;i++) {
//      int order=l_seq[i+1]+1;

//      for (int j=1;j<=n;j++) {
//        order-=l_ele[j];
//        if (!order) {
//          l_ret[i]=j;
//          l_ele[j]=0;
//          break;
//        }
//      }

////      l_ret[i]=l_ele[l_seq[i+1]];
////      l_ele.erase(l_ele.begin()+l_seq[i+1]);
//    }


//    string str_ret;

//    for(auto it:l_ret)
//    {
//      str_ret+=std::to_string(it);
//    }
    return str_ret;

  }
};
