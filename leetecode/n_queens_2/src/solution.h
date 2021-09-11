#include <vector>
#include <iostream>
#include <vector>

using namespace std;




  class Solution {
  public:

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

      int totalNQueens(int n) {

//        vector<vector<int> > arr_result;

        int ret_count=0;

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


          if (l_remain.size() == 0) {
//            arr_result.push_back(l_target);
            ret_count++;
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

        return ret_count;



      }
  };


