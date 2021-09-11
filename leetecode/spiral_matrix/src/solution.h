#include <vector>
#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {

    /// h-1 w-1
    /// (0,0,h,w)
    /// (1,1,h-2,w-2)
    /// (2,2,h-4,w-4)

    /// 每次计算一个矩形的指定部分
    /// if(w==0||h==0) return 0
    /// if(w==1){... return}
    /// if(h==1){... return}
    /// else
    /// 将该矩形的四边上的点按照顺时针加入结构队列，
    /// 重新缺定矩阵的位置，
    /// - 若两变均不为0，则开始新的循环
    /// - 否则，退出

    vector<int>  l_res;
    if(matrix.size()==0||matrix[0].size()==0){
      return l_res;
    }

    spiralHelper(matrix,l_res,0,0,matrix[0].size(),matrix.size());

    return l_res;

  }



  /// 返回值:true 进一步计算，false计算结束
  bool spiralHelper(vector<vector<int>>& matrix,
                    vector<int> &l_res,
                    int v_x,int v_y,int v_w,int v_h)
  {
    if (v_w == 0|| v_h ==0) {
      return false;
    }
    else if(v_w == 1)
    {
      for (int i=v_y;i<v_y+v_h;i++) {
        l_res.push_back(matrix[i][v_x]);
      }
      return false;
    }
    else if(v_h == 1)
    {
      for (int i=v_x;i<v_x+v_w;i++) {
        l_res.push_back(matrix[v_y][i]);
      }
      return false;
    }
    else{

      for(int i=v_x;i<v_x+v_w;i++)
      {
        l_res.push_back(matrix[v_y][i]);
      }

      for(int i=v_y+1;i<v_y+v_h;i++)
      {
        l_res.push_back(matrix[i][v_w+v_x-1]);
      }

      for(int i=v_x+v_w-2;i>=v_x;i--)
      {
        //          l_res.push_back(matrix[v_y][i]);
        l_res.push_back(matrix[v_y+v_h-1][i]);
      }

      for(int i=v_y+v_h-2;i>v_y;i--)
      {
        l_res.push_back(matrix[i][v_x]);
      }

      return spiralHelper(matrix,l_res,v_x+1,v_y+1,v_w-2,v_h-2);
    }
  }

};
