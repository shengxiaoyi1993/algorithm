#include <vector>
#include <iostream>
#include <vector>

using namespace std;

//A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

//The robot can only move either down or right at any point in time.
//The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

//Now consider if some obstacles are added to the grids. How many unique paths would there be?

//An obstacle and space is marked as 1 and 0 respectively in the grid.



//Example 1:

//Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
//Output: 2
//Explanation: There is one obstacle in the middle of the 3x3 grid above.
//There are two ways to reach the bottom-right corner:
//1. Right -> Right -> Down -> Down
//2. Down -> Down -> Right -> Right

//Example 2:

//Input: obstacleGrid = [[0,1],[0,0]]
//Output: 1



//Constraints:

//    m == obstacleGrid.length
//    n == obstacleGrid[i].length
//    1 <= m, n <= 100
//    obstacleGrid[i][j] is 0 or 1.

//class Node
//{
//public:
//  Node(int v_x,int v_y,int v_flag):
//    __x(v_x),__y(v_y),__flag(v_flag)
//  {

//  }

//public:
//  int __x;
//  int __y;
//  int __flag;

//};


//class Solution {


//public:


//  /// 假设障碍A，覆盖障碍B，途经障碍A的途径与途径障碍B的途径有重合
//  /// A，B没有覆盖关系，则途径A，B的路径没有重合
//  /// 覆盖关系计算， Ax>=Bx&&Ay>=By则有覆盖关系
//  /// 考虑多重覆盖的关系
//  /// 即A覆盖B，B覆盖C,已知途径A，途径B，途径C的路径数，
//  /// 且有特殊情况:途经A且途经B且途经C的路径数,Y(A)N(BC),Y(B)N(AC),Y(C)N(AB),Y(AB)N(C),Y(AC)N(B),Y(BC)N(A)
//  /// 情形较为复杂，后议
//  /// 有障碍情况下的路径总数为

//  /// 不使用上一题的结论进行考虑
//  /// - 每次考虑一个点，假设已有的数据中都是满足条件
//  /// ...考虑一个点X时，我们想移除只经过X的情况，其复杂度可能低于原题   分别考虑同时经过若干点情况


//  /// 由若干不包含的障碍组成

//  /// 可以计算经过障碍的路径总数，再由原总数减去该值
//  /// 障碍可以分成不包含的若干组，

//  /// 逐个进行遍历[0][0] -> [m-1][n-1]
//  /// x 从0->m-1逐个遍历，y

//  /// 一个点的输出方向有三个flag,0：y向增加，1：x向增加，2：返回，三者有次序
//  /// 保存一个表记录经过的点和点到下一点的行进方向（0，1）
//  /// 逐个列举，遇到中间有阻碍就跳过，先确定y再决定x
//  /// 假设每次循环，当前点总是可用，已知当前点，每次循环，修改点的位置或者，点的移动方向
//  /// 循环的计算：按照0->1->2的顺序进行旧案
//  ///
//  /// 取列表的最后一点
//  /// - 0：y向增加获取新点，检查是否是阻碍与超出范围
//  ///  > 是，则不增加该点原点，flag=1,
//  ///   - 否，检查是否到达终点
//  ///   > 是，记录该列表，设置方向为下一个：0则1
//  ///   > 否增列表增加该点，设置flag=0，
//  /// - 1:x向增加获取新点，检查是否是阻碍与超出范围
//  ///  > 是，则不增加该点原点，flag=2,
//  ///   - 否，检查是否到达终点
//  ///   > 是，记录该列表，设置方向为下一个：1则2
//  ///   > 否，增列表增加该点，设置flag=0，
//  /// - 2:列表是否为空
//  ///  > 列表为空，则结束
//  ///  > 删除列表的末点，原用新的末点作为工作点，设置方向为下一个，0->1,1->2
//  ///

//  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

//    if (obstacleGrid[0][0] == 1) {
//      return 0;
//    }


//    int height=obstacleGrid.size();
//    int width=obstacleGrid[0].size();

//    if (height==1&&width==1) {
//      if (obstacleGrid[0][0] == 0) {
//        return 1;
//      }
//      else{
//        return 0;
//      }

//    }
//    int num_valid=0;

//    vector<Node> nodes;
//    nodes.push_back(Node(0,0,0));




//    while (nodes.size()>0) {

////      for (auto it:nodes) {
////        std::cout<<"("<<it.__x<<","<<it.__y<<","<<it.__flag<<") ";
////      }
////      std::cout<<std::endl;

//      Node node_cur=*nodes.rbegin();
//      switch (node_cur.__flag) {
//        case 0:{
//          Node node_new=Node(node_cur.__x,node_cur.__y+1,0);
//          if (node_new.__x<width
//              && node_new.__y<height
//              && obstacleGrid[node_new.__y][node_new.__x]==0) {

//            if (node_new.__x == width-1 && node_new.__y == height-1) {
//              num_valid++;
//              (*nodes.rbegin()).__flag=1;
//            }
//            else {
//              nodes.push_back(node_new);
//            }

//          }
//          else{
//            (*nodes.rbegin()).__flag=1;
//          }
//          break;
//        }
//        case 1:{
//          Node node_new=Node(node_cur.__x+1,node_cur.__y,0);
//          if (node_new.__x<width
//              && node_new.__y<height
//              && obstacleGrid[node_new.__y][node_new.__x]==0) {

//            if (node_new.__x == width-1 && node_new.__y == height-1) {
//              num_valid++;
//              (*nodes.rbegin()).__flag=2;
//            }
//            else {
//              nodes.push_back(node_new);
//            }

//          }
//          else{
//            (*nodes.rbegin()).__flag=2;
//          }
//          break;

//        }
//        case 2:{
////          nodes.erase(nodes.end());
//          nodes.pop_back();
//          if (nodes.size() > 0) {
//            (*nodes.rbegin()).__flag++;
//          }
//          break;
//        }
//        default:{
//          std::cout<<"error !"<<std::endl;
//        }

//      }
//    }

//    return num_valid;

//  }

//};



class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // 与62相同 建立一个2维数组来储存dp结果
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++)
        {
            dp[i][0] = 1;
        }

        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++)
        {
            dp[0][j] = 1;
        }
        for (int i = 1, j = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

