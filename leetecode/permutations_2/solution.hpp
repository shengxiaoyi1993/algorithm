#include <iostream>
#include <map>
using namespace std;
//
// 47. Permutations II
//
// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
// Example:
//
// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]
//
//

//统计每个字符的个数
//使用迭代分配字符

//迭代函数 输入 [统计字符数量] [已经处理的标识] [返回结果]



class Solution {
public:
  void traceBack(map<int ,int>& v_map,
    int v_pos,int v_size,vector<int> & v_keys,vector<int> & v_array,
    vector<vector<int> >& v_res){
      if(v_pos == v_size){
        v_res.push_back(v_array);
        return ;
      }
      else{
        for(auto item:v_keys){
          if(v_map[item] == 0){
            continue;
          }
          else{
            v_map[item]--;
            v_array.push_back(item);
            traceBack(v_map,v_pos+1,v_size,v_keys,v_array,v_res);
            v_array.pop_back();
            v_map[item]++;
          }
        }
      }

      return ;

  }

    vector<vector<int> > permuteUnique(vector<int>& nums) {
      map<int ,int> v_map;
      vector<int> v_keys;
      vector<int> v_array;

      vector<vector<int> > v_res;
      for(auto item:nums){
        v_map[item]++;
      }

      for(auto item:v_map){
        v_keys.push_back(item.first);
      }
      
      traceBack(v_map,0,nums.size(),v_keys,v_array,v_res);
      return v_res;

    }
};
