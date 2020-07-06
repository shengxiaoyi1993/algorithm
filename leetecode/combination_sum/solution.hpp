// 39. Combination Sum
//
// Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// The same repeated number may be chosen from candidates unlimited number of times.
//
// Note:
//
//     All numbers (including target) will be positive integers.
//     The solution set must not contain duplicate combinations.
//
// Example 1:
//
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
//
// Example 2:
//
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]

//寻找和为目标值的数字集合
//使用递归
//若集合的元素数量为0，返回空
//若集合的数量为1，target%element是否为零
//  若为零，返回字符串
//  若不为零，返回空
//逐个选定某一值的数量，直到数值和不大于target。计算剩余值
//  剩余值为0，添加结果，继续
//  若剩余值不为0，就能确定一个子题目，计算子题目的返回值
//    若返回不为空，则添加特定值后添加进结果，继续
//    若返回为空，继续



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
// std::cout << "input: "  ;
// for (size_t i = 0; i < candidates.size(); i++) {
//   std::cout << candidates[i]<<" " ;
//   /* code */
// }
// std::cout  << '\n';
// std::cout << "target: " <<target<< '\n';


      vector<vector<int> >  reslist;
      int size_candidates=candidates.size();
      if(size_candidates==0){
      }
      else if(size_candidates == 1){
        if(target%candidates[0] == 0){
          vector<int> tmplist;

          for (size_t i = 0; i < target/candidates[0]; i++) {
            tmplist.push_back(candidates[0]);
          }
          reslist.push_back(tmplist);
        }
      }
      else{
        for (size_t i = 0; i*candidates[0] <= target; i++) {
          int tmptarget=target-i*candidates[0];
          if(tmptarget == 0){
            vector<int> tmplist;
            for (size_t j = 0; j < i; j++) {
              tmplist.push_back(candidates[0]);
            }
            reslist.push_back(tmplist);
          }
          else{
            vector<int> tmp_candidates;
            for (size_t j = 1; j < size_candidates; j++) {
              tmp_candidates.push_back(candidates[j]);
              /* code */
            }
            vector<vector<int> > tmpresult=combinationSum(tmp_candidates,tmptarget);
            int size_tmpresult=tmpresult.size();
            for (size_t j = 0; j < size_tmpresult; j++) {
              for (size_t k = 0; k < i; k++) {
                tmpresult[j].insert(tmpresult[j].begin(),candidates[0]);
              }
              reslist.push_back(tmpresult[j]);
            }
          }
        }
      }

// std::cout << "output:" << '\n';
// for (size_t i = 0; i < reslist.size(); i++) {
//   std::cout <<i<< ":" <<" ";
//   for (size_t j = 0; j < reslist[j].size(); j++) {
//     std::cout << j << " ";
//   }
//   std::cout  << '\n';
//
// }


      return reslist;
    }
};
