#include <vector>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;


//79. Word Search

//Given an m x n grid of characters board and a string word, return true if word exists in the grid.

//The word can be constructed from letters of sequentially adjacent cells,
//where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.



//Example 1:

//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
//Output: true

//Example 2:

//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
//Output: true

//Example 3:

//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
//Output: false



//Constraints:

//    m == board.length
//    n = board[i].length
//    1 <= m, n <= 6
//    1 <= word.length <= 15
//    board and word consists of only lowercase and uppercase English letters.


/// 设置辅助矩阵，0则未使用，1则已使用
/// 寻找第一个字母，将所有找到的数据放入一个数组
/// >找到，设置辅助矩阵对应子母为1
/// >未找到设置，返回失败

/// 逐个按序寻找子母
/// 每找到一个，在其周围寻找下一个子母，直至所有字母被找到或者有字母找不到
class Solution {
public:

  bool findFirst(const vector<vector<char>>& board,int &m, int &n,char ch)
  {


    for (;m<board.size();m++,n=0) {
      for (;n<board[0].size();n++) {
//        std::cout<<"board[m][n]:"<<board[m][n]<<endl;
//        std::cout<<"ch:"<<ch<<endl;
//        std::cout<<"m:"<<m<<endl;
//        std::cout<<"n:"<<n<<endl;

        if (board[m][n] == ch) {
          return true;
        }
      }
    }
    return false;
  }

  ///  假设总是矩阵中的值前移
  bool getNext(int &h, int &w,int v_height,int v_width)
  {
    if (w==v_width-1) {
      w=0;
      h++;
      if (h >= v_height) {
        return false;
      }
    }
    else{
      w++;
    }
    return true;
  }

  bool isInRange(vector<int> & v_point,int v_height,int v_width)
  {
    if (v_point[0]>=0&& v_point[0]<v_height && v_point[1]>=0 && v_point[1]<v_width) {
      return true;
    }
    else{
      return false;
    }

  }


  bool exist(vector<vector<char>>& board, string word)
  {

    vector<vector<int>> arr_dir={{0,1},{1,0},{0,-1},{-1,0}};

    int height=board.size();
    int width=board[0].size();

    int first_w=0;
    int first_h=0;

    vector<vector<int>> arr_help(height,vector<int>(width,0));
    vector<vector<int>> point_find(word.size()-1,{0,0});



    while (findFirst(board,first_h,first_w,word[0]))
    {

      if (word.size()==1) {
        return true;
      }
      vector<int> point_help(word.size()-1,0);

      arr_help[first_h][first_w]=1;
      int count_ele=0;
      point_find[0]={first_h,first_w};

      /// 此时已知起始点，已确定点，已确定点的辅助矩阵，需要逐个寻找目标字符串上的点直至所有点被找到
      /// 若找到，直接返回true
      /// 若跳出循环，则开始下一个初始点
      while(true)
      {


//        for (auto it:point_find) {
//          std::cout<<"("<<it[0]<<","<<it[1]<<") ";
//        }
//        std::cout<<endl;

//        std::cout<<"count_ele:"<<count_ele<<endl;


//        sleep(1);

        ///count_ele 标记当前点
        /// point_help[] 标记当前遍历的点，当>3时置为0，回退count_ele


        if (count_ele<0) {
          break;
        }

        if (point_help[count_ele]>3) {
          point_help[count_ele]=0;
          arr_help[point_find[count_ele][0]][point_find[count_ele][1]]=0;

          count_ele--;
          continue;
        }

        vector<int> point_tmp{point_find[count_ele][0]+arr_dir[point_help[count_ele] ][0]
              ,point_find[count_ele][1]+arr_dir[point_help[count_ele]][1]};

//        std::cout<<"("<<point_tmp[0]<<","<<point_tmp[1]<<") ";
//        std::cout<<endl;

        if (!isInRange(point_tmp,height,width)) {
//          std::cout<<"out of range"<<endl;
          point_help[count_ele]++;
          continue;
        }

        /// 跳过已找到的
        if (arr_help[point_tmp[0]][point_tmp[1]] == 1) {
          point_help[count_ele]++;
          continue;
        }

        /// 此时比较下一个字母
        /// >匹配则point_find添加该点
        /// >未匹配则更换方向
        if (word[count_ele+1] == board[point_tmp[0]][point_tmp[1]]) {
          if (count_ele == word.size()-2) {
            return true;
          }
          point_help[count_ele]++;
          count_ele++;
          arr_help[point_tmp[0]][point_tmp[1]]=1;
          point_find[count_ele]=point_tmp;

        }
        else{
          point_help[count_ele]++;

        }
      }

      /// 跳出循环，说明这个点没有用
      if (!getNext(first_h,first_w,height,width)) {
        return false;
      }

    }
    return false;
  }
};


//新手最近练习了回溯算法，根据@Tom也要Offer大佬总结的回溯六步走。
//1.画递归树，找状态变量。
//2.结束条件
//3.选择列表
//4.枝剪
//5.选择，递归进入下一层
//6.撤销选择

//然后我们来分析本题：
//1.状态变量就是当前找到第几个字符了、(还有当前的位置见3)
//2.结束条件显而易见就是找到最后一个字符了。
//3.选择列表就是当前位置的上下左右，所以要加一个状态变量就是自己当前位置。
//由于不能选择重复的字符，所以要列一个used列表，如果选择了就标志1，没选就标志0。
//4.枝剪掉上下左右不是目标字符的选项
//56略
//代码
//class Solution {
//public:
//    int used[6][6]; //用过的字符
//    int found = 0; //找到了
//    bool exist(vector<vector<char>>& board, string word) {
//        for(int x=0;x<board.size();x++){
//            for(int y=0;y<board[0].size();y++){
//                if(board[x][y]==word[0]){
//                    dfs(board,x,y,word,1);
//                }
//            }
//        }
//        return found;
//    }

//    void dfs(vector<vector<char>>& board,int x,int y,string word,int location){
//        if(location == word.size()){//结束条件
//            found = 1;
//            return;
//        }
//        used[x][y]=1;//选择
//        if(y+1<board[0].size() && board[x][y+1]==word[location] && !used[x][y+1]){
//            dfs(board,x,y+1,word,location+1);
//        }
//        if(y-1>=0 && board[x][y-1]==word[location] && !used[x][y-1]){
//            dfs(board,x,y-1,word,location+1);
//        }
//        if(x+1<board.size() && board[x+1][y]==word[location] && !used[x+1][y]){
//            dfs(board,x+1,y,word,location+1);
//        }
//        if(x-1>=0 && board[x-1][y]==word[location] && !used[x-1][y]){
//            dfs(board,x-1,y,word,location+1);
//        }
//        used[x][y]=0; //撤销
//    }
//};

