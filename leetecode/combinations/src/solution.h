#include <vector>
#include <iostream>
#include <vector>


//77. Combinations

//Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

//You may return the answer in any order.



//Example 1:

//Input: n = 4, k = 2
//Output:
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//]

//Example 2:

//Input: n = 1, k = 1
//Output: [[1]]



//Constraints:

//    1 <= n <= 20
//    1 <= k <= n



using namespace std;

/// 按顺序选择[1,n]中的数，选择后从范围中删除
/// 假设结果中的数都是从小到大排列
/// 每次计算完成后最后的数加一若超出范围则前面的的数加一，依次类推
/// 直到到达某个终值时结束

/// 问题在于可能要进行多次循环，才能完成依次取值
/// 需要有一个值标定该次循环应计算的值

/// <>或者有建议方法将数据分布于某一数据结构，然后从该数据结构中顺次读取就能快速计算出结果


/// 假定循环中的都是基于前一次结果，然后在层次上计算出一个满足条件的值（若没有则为前值,若有则添加到），
/// ...此处两两种情况，计算层在中件层，下一次计算需要根据当前层的值加一，
/// ...然后设置下一次计算的层次
/// 赋初值
/// 将该值添加到结果列表
/// 设置计算层次为k-1
/// 计算层次为0时，若item[0]++后，等与n-k+1,则获得最后一个数据组{n-k+1,...,n},
class Solution {
public:


    vector<vector<int>> combine(int n, int k) {

      vector<vector<int>>  arr_item;
      if (k>n) {
        return arr_item;
      }

      vector<int> item(k,0);
      for (int i=0;i<k;i++) {
        item[i]=i+1;
      }
      arr_item.push_back(item);
      if (n==k) {
        return arr_item;
      }


      int layer=k-1;
      while (true) {
        item[layer]++;


        if (item[layer]>n+k-layer-1) {
          item[layer]--;
          layer--;
          continue;
        }

        if (layer ==0 && item[layer] == n-k+1 ) {
          for (int i=0;i<k;i++) {
            item[i]=n-k+1+i;
          }
          arr_item.push_back(item);
          break;
        }

        if (layer == k-1) {
          arr_item.push_back(item);
          if (item[layer] == n) {
            layer--;
            continue;
          }
        }
        else{
          layer++;
          item[layer]=item[layer-1];
        }

      }

      return arr_item;
    }

};
