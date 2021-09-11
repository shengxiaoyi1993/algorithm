#include <vector>
#include <iostream>
#include <vector>

using namespace std;

//The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

//Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

//Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.



//Example 1:

//Input: n = 4
//Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

//Example 2:

//Input: n = 1
//Output: [["Q"]]



//Constraints:

//    1 <= n <= 9

//来源：力扣（LeetCode）
//链接：https://leetcode-cn.com/problems/n-queens
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。




class Solution {
public:

  //  bool solveNum(vector<int> &l_num,int &seq,vector<int> &l_add);

  /// 计算最后一个数值是否满足要求
  bool isValid(const vector<int>  &l_num, int size,int num){
//    int size=l_num.size();

    for(int i=0;i<size;i++)
    {

      if ((l_num[i]-num ==size-i)
          ||(l_num[i]-num == -(size-i))
          ) {
        return false;
      }
    }
    return true;
  }

  bool isAllValid(const vector<int>  &l_num)
  {
    for (int i=1;i<l_num.size();i++) {
      if (!isValid(l_num,i,l_num[i])) {
        return false;
      }
    }
    return true;

  }

  void printList(const vector<int>  &l_num){
    for (auto it:l_num) {
      std::cout<<it<<" ";
    }
    std::cout<<std::endl;

  }


  void printArray(const vector<vector<int> > &v_arr){
    std::cout<<"---------arr---------"<<std::endl;

    for (int i=0;i<v_arr.size();i++) {
      std::cout<<""<<i<<":";
      for (auto it:v_arr[i]) {
        std::cout<<" "<<it;
      }
      std::cout<<std::endl;
    }
    std::cout<<"==========arr=========="<<std::endl;

  }


  vector<vector<string> > solveNQueens(int n) {

    vector<vector<int> > arr_result;

    vector<vector<int> > arr_used;
    vector<int > l_remain;
    vector<int > l_target;

    for(int i=0;i<n;i++){
      l_remain.push_back(i);
      arr_used.push_back({});
    }

    /// 穷举法
    /// 当所有没有可用数时,回退,即清除当前行的数据

    /// 若无剩余元素,则记录测试数组到结果矩阵,同时删除最上层的元素,同时添加到剩余数组中,重复
    /// 在剩余数组中寻找一个元素,该元素不在已使用数组的第 (当未加入时,测试数组的元素数量)层
    ///  若有,取该数加入当前测试数组,同时加入记录矩阵的第 (当未加入时,测试数组的元素数量)层
    ///  若无,则删除矩阵的第 (当未加入时,测试数组的元素数量)层,
    ///   若当前层不是第0层同时删除最上层的元素,同时添加到剩余数组中,重复
    ///   若当前层是第0层,则已遍历所有情况跳出循环
    /// 验证是否有效
    ///  若无效,删除最上层的元素,同时添加到剩余数组中,重复
    ///  若有效,重复


    int count =0;
    while (true) {

//      count++;
//      if (count ==20) {
//        break;
//      }

//      std::cout<<"l_target:"<<l_target.size()<<">>";
//      printList(l_target);

//      std::cout<<"l_remain:"<<l_remain.size()<<">>";
//      printList(l_remain);

//      printArray(arr_used);


      if (l_remain.size() == 0) {
        arr_result.push_back(l_target);
        l_remain.push_back(l_target[l_target.size()-1]);
        l_target.erase(l_target.begin()+l_target.size()-1);

      }

      int seq_num;
      bool find=false;
      for (int i=0;i<l_remain.size();i++) {

        bool isused=false;
        for (int j=0;j<arr_used[l_target.size()].size();j++) {
          if (arr_used[l_target.size()][j] == l_remain[i] ) {
            isused=true;
            break;
          }
        }

        if (!isused) {
          find=true;
          seq_num=i;
          break;
        }
      }

      ///  若有,取该数加入当前测试数组,同时加入记录矩阵的第 (当未加入时,测试数组的元素数量)层
      if (find) {
//        std::cout<<"find"<<endl;
        arr_used[l_target.size()].push_back(l_remain[seq_num]);

//        printArray(arr_used);

        l_target.push_back(l_remain[seq_num]);
        l_remain.erase(l_remain.begin()+seq_num);
      }
      else{
        ///  若无,则清空矩阵的第 (当未加入时,测试数组的元素数量)层,

        if ( l_target.size() == 0 ) {
//          std::cout<<"break"<<endl;

          ///   若当前层是第0层,则已遍历所有情况跳出循环
          break;
        }
        else{
          ///   若当前层不是第0层同时删除最上层的元素,同时添加到剩余数组中,重复
          arr_used[l_target.size()].clear();
          l_remain.push_back(l_target[l_target.size()-1]);
          l_target.erase(l_target.begin()+l_target.size()-1);
          continue;
        }
      }


      /// 验证是否有效
      if (isAllValid(l_target)) {
        ///  若有效,重复
        continue;
      }
      else{
        l_remain.push_back(l_target[l_target.size()-1]);
        l_target.erase(l_target.begin()+l_target.size()-1);
      }
    }

    vector<vector<string> >  l;

    for (int i=0;i<arr_result.size();i++) {
      vector<string> l_str_dot;

      for (int j=0;j<arr_result[i].size();j++) {
        string  str_dot(n,'.');
        str_dot[arr_result[i][j]]='Q';
        l_str_dot.push_back(str_dot);
      }
      l.push_back(l_str_dot);


    }

    return l;

  }






};
