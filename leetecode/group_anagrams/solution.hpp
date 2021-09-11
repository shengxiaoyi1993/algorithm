#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// 49. Group Anagrams
//
// Given an array of strings, group anagrams together.
//
// Example:
//
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
//
// Note:
//
//     All inputs will be in lowercase.
//     The order of your output does not matter.
//

// 以string作为标识符
class Solution {
    unordered_map<string, vector<string> > m;
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > ans;
        for (auto& e : strs){
            string tt = e;
            std::sort(e.begin(), e.end());
            m[e].emplace_back(tt);
        }
        for (auto& e : m){
            ans.emplace_back(e.second);
        }

        return ans;
    }
};


//用字符的计数来标识
//
// class Solution {
// public:
//
//   map<string,int> getMap(const string &v_str){
//     map<string,int> v_map;
//     for (size_t i = 0; i < v_str.size(); i++) {
//       v_map[v_str[i]]++;
//     }
//   }
//   bool isMapEgual(const map<string ,int>& v_map0,const map<string,int>& v_map1){
//     if(v_map0.size()!=v_map1.size()){
//       return false;
//     }
//     else{
//       for(map<int,int>::iterator it = v_map0.begin(); it != v_map0.end(); it++) {
//         if(v_map1[it->first] != it->second){
//           return false;
//         }
//       }
//       return true;
//     }
//   }
//     vector<vector<string> > groupAnagrams(vector<string>& strs) {
//       vector<vector<string> > v_lists;
//       vector<map<string,int> > v_maps;
//       for (size_t i = 0; i < strs.size(); i++) {
//         map<string,int> tmpmap=getMap(strs[i]);
//         if(v_maps.size()==0){
//           v_maps.push_back(tmpmap);
//           vector<string> tmplist;
//           tmplist.push_back(strs[i]);
//           v_lists.push_back(tmplist);
//         }
//         else{
//           bool flag=false;
//           for (size_t j = 0; j < v_maps.size(); j++) {
//             if(isMapEgual(tmplist,v_maps[j])){
//
//               flag=true;
//               break;
//             }
//           }
//         }
//
//       }
//     }
// };
