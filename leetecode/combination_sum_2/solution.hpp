// 40. Combination Sum II
//
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// Each number in candidates may only be used once in the combination.
//
// Note:
//
//     All numbers (including target) will be positive integers.
//     The solution set must not contain duplicate combinations.
//
// Example 1:
//
// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
//
// Example 2:
//
// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]

//思路
//迭代法求解
//若candidates为空，返回空
//若candidates size为1，比较元素与target
//  若相等，返回该元素的单元素
//  若不相等，返回空
//若candidates——size>1,取第一个元素candidates[0]
//  若candidates[0]>target,后面的元素不包含该元素，计算后面的数，返回列表
//  若candidates[1]==target，直接得到单元素列表，或者计算后面
//（后面逻辑比较复杂，先考虑其他思路）

//直接用穷举法求解
//循环一次单个元素
//循环一次逐渐增加元素数量，每次的元素取之前和小与

//思路3-递归方法 (该方法不能区分重复元素的包含问题)
//对于某一元素，包含两种可能，包含和不包含
//重新定义一个函数
// calCombination2(candidates,target,start)
// 对于candidates.size-start==1.计算candidates[start]元素是否等于target,返回结果列表
// 对于candidates.size-start>1，
//  对于candidates[start]
//    包含该元素，tmp_target=target-elem
//      若tmp_target==0,返回结果
//      若tmp_target>0,start++，重新执行该函数，得到结果
//        若结果为空
//        若结果不为空，则结果添加candidates[start]，添加到结果列表中
//      若tmp_target<0
//    不包含该元素，记录，tmp_target=target
//      若结果为空
//      若结果不为空，则添加到结果列表中
//    返回结果列表

// {
//   //补救方案
//   // 1. 用一个表，记录处理过的元素（但是对于多个重复元素表的表，处理复杂）
//   //      若表中包含该元素，若
//   //         若元素被包含，则该元素可以被包含
//   //         若元素不被包含，则该元素不能被包含
//   //（及存在三种情况，1.均不包含 2. 只包含一个 3.包含两个）
// }


//思路4-基于数据分类之后的运算
//  建立[数字 数量]表，然后

// class Solution {
// public:
//     map<vector<int>, int> item;
//     void backtrack(vector<int>& candidates, int target, int sum, int first, vector<int>& nums){
//         if(sum == target){
//             item[nums] = 1;
//             return;
//         }
//         for(int i=first; i<candidates.size(); i++){
//             if(sum+candidates[i] <= target){
//                 nums.push_back(candidates[i]);
//                 backtrack(candidates, target, sum+candidates[i], i+1, nums);
//                 nums.pop_back();
//             }
//         }
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         vector<vector<int>> res;
//         vector<int> nums;
//         sort(candidates.begin(), candidates.end());
//         backtrack(candidates, target, 0, 0, nums);
//         for(auto t:item){
//             res.push_back(t.first);
//         }
//         return res;
//     }
// };
//



//参考方案：
//基于排序与map避免结果的重复
//  假设
//    1. 经过排序后，得到的结果也是非严格单调的
//    2. 经过map存数据时，若将1维vector数组作为键值，该值不会重复
//    3. 恰好等于target时，需要知道整个数组，即需要将变量传递到深层
//    4. 分为存在与不存在该元素
//实现步骤
//1. 定义全局变量map
//2. 对数组进行排序
//3. 处理第一个元素
//  包含
//  不包含

//迭代函数
//  输入：当前位置，原数据,target,之前的数据
//  输出：结果
//步骤
//  添加当前位置的元素，计算元素和
//    若和等于target,将结果计入map
//    若和小于target，将位置+1，调用该函数
//    否则，返回



//主函数
//  排序
//  调用迭代函数
//  转换map为结果
//  输出结果

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  map<vector<int>,int>gmap;
  void iterate(vector<int>& candidates,vector<int>& v_rets,int v_sum ,int target,int v_pos){
    // cout<<"pos:"<<v_pos<<endl;
    if(v_pos<candidates.size()){

      //包含该元素
      int tmpsum=candidates[v_pos]+v_sum;
      v_rets.push_back(candidates[v_pos]);
      // cout<<"tmpsum:"<<tmpsum<<endl;
      // cout<<"target:"<<target<<endl;

      if(tmpsum == target){
        // std::cout << "/* message */" << '\n';
        gmap[v_rets]=1;
      }
      else if(tmpsum < target){
        iterate(candidates,v_rets,tmpsum,target,v_pos+1);
      }
      v_rets.pop_back();

      //不包含该元素
      iterate(candidates,v_rets,v_sum,target,v_pos+1);

    }
  }



  vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<int> v_rets;
    iterate(candidates,v_rets,0,target,0);
      vector<vector<int> >  lists;
        for(auto t:gmap){
          lists.push_back(t.first);
        }
        return lists;
  }

//-----------------------------------------------------------------------------------
    // vector<vector<int> > combinationSum2_sup(vector<int>& candidates, int target,int start) {
    //   vector<vector<int> > list_ret;
    //   if(candidates.size()-start==1){
    //     if(candidates[start] == target){
    //       vector<int>  tmplilist;
    //       tmplilist.push_back(candidates[start]);
    //       list_ret.push_back(tmplilist);
    //     }
    //   }//end of candidates.size()-start==1
    //   else if(candidates.size()-start > 1){
    //
    //
    //     {//include
    //       int tmptarget=target-candidates[start];
    //       if(tmptarget == 0){
    //         vector<int>  tmplilist;
    //         tmplilist.push_back(candidates[start]);
    //         list_ret.push_back(tmplilist);
    //       }
    //       else if(tmptarget > 0){
    //         vector<vector<int> > tmp_rets=combinationSum2_sup(candidates,tmptarget,start+1);
    //         for (size_t i = 0; i < tmp_rets.size(); i++) {
    //           tmp_rets[i].push_back(candidates[start]);
    //           list_ret.push_back(tmp_rets[i]);
    //         }
    //       }
    //     }//end of include
    //
    //     {//not include
    //       vector<vector<int> > tmp_rets=combinationSum2_sup(candidates,target,start+1);
    //       for (size_t i = 0; i < tmp_rets.size(); i++) {
    //         list_ret.push_back(tmp_rets[i]);
    //       }
    //     }//end of not include
    //   }
    //   return list_ret;
    // }
    // vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
    //   return combinationSum2_sup(candidates,target,0);
    // }


    //-------------------------------------------------------------------------
        // map<vector<int>, int> item;
        // void backtrack(vector<int>& candidates, int target, int sum, int first, vector<int>& nums){
        //     if(sum == target){
        //         item[nums] = 1;
        //         return;
        //     }
        //     for(int i=first; i<candidates.size(); i++){
        //         if(sum+candidates[i] <= target){
        //             nums.push_back(candidates[i]);
        //             backtrack(candidates, target, sum+candidates[i], i+1, nums);
        //             nums.pop_back();
        //         }
        //     }
        // }
        // vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        //     vector<vector<int> > res;
        //     vector<int> nums;
        //     sort(candidates.begin(), candidates.end());
        //     backtrack(candidates, target, 0, 0, nums);
        //     for(auto t:item){
        //         res.push_back(t.first);
        //     }
        //     return res;
        // }

};
