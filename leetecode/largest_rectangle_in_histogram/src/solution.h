#include <vector>
#include <iostream>
#include <vector>
#include <map>

using namespace std;



//84. Largest Rectangle in Histogram
//Given an array of integers heights representing the histogram's bar height
//where the width of each bar is 1, return the area of the largest rectangle in the histogram.



//Example 1:

//Input: heights = [2,1,5,6,2,3]
//Output: 10
//Explanation: The above is a histogram where width of each bar is 1.
//The largest rectangle is shown in the red area, which has an area = 10 units.

//Example 2:

//Input: heights = [2,4]
//Output: 4



//Constraints:

//    1 <= heights.length <= 10^5
//    0 <= heights[i] <= 10^4

//connect(gateTabWidget0,&GuiGateTab::sgl_updateData,
//        [&](const ns_uvdm100_sw_def::ns_db::T_DEVICE_GROUP_DS &v_devgrp,
//        const ns_uvdm100_sw_def::DeviceGroupInfo &v_devgrp_info)
//{

//  auto devgrp_tmp=v_devgrp;
//  auto devgrp_info_tmp=v_devgrp_info;


//  MACRO_GLOG_INFO("v_devgrp:"<<devgrp_tmp.jsonObj().ToFormattedString());
//  MACRO_GLOG_INFO("v_devgrp_info:"<<devgrp_info_tmp.jsonObj().ToFormattedString());

//  ///grp
//  auto pos_grp=std::find_if(
//        __l_dev_grp.begin(),
//        __l_dev_grp.end(),
//        [&](const ns_uvdm100_sw_def::ns_db::T_DEVICE_GROUP_DS&v_grp){
//    return v_grp.DEVICE_GROUP_ID==v_devgrp.DEVICE_GROUP_ID;
//  });

//  if (pos_grp != __l_dev_grp.end()) {
//    (*pos_grp)=v_devgrp;
//  }
//  else{/// 未找到
//    MACRO_GLOG_ERROR("Fail to find T_DEVICE_GROUP_DS in __l_dev_grp");
//  }

//  /// 根据ip查找UVSS设备
//  if (v_devgrp_info.__uvss_dev.IP != "") {
//    auto pos_uvss=std::find_if(
//          __dev_config.__l_dev_uvss.begin(),
//          __dev_config.__l_dev_uvss.end(),
//          [&](const ns_uvdm100_sw_def::ns_db::T_UVSS_CAMERA_DS&v_cam){
//      return v_cam.IP==v_devgrp_info.__uvss_dev.IP;
//    });
//    if ( pos_uvss != __dev_config.__l_dev_uvss.end()) {
//      *pos_uvss=v_devgrp_info.__uvss_dev;
//    }
//    else{
//      MACRO_GLOG_ERROR("Fail to find T_UVSS_CAMERA_DS in __dev_config");
//      __dev_config.__l_dev_uvss.push_back(v_devgrp_info.__uvss_dev);

//    }
//  }


/// 计算最大的矩形
/// 即为差值，int
/// 获取每个高度连续块的数量 ，每高度连续块的最大数量
/// 每个高度连续块的数量：必然小>=大
///
/// 逐行统计
/// 获取列高，对连续块进行记录，当当前列高小于记录，求某一矩形面积，若大于最大值则记录
  class Solution {
  public:



//      int largestRectangleArea(vector<int>& heights)
//      {
//        int  max=0;
////        int record[106]={0};

//        std::map<int,int>record;
////        record[0]=heights[0];
//        for (int i=0;i<=heights[0]; i++) {
//          record[i]=1;
//        }

//        for (size_t i=1;i<heights.size();i++)
//        {
//          if (heights[i] >= heights[i-1] ) {
//            for (int j=1;j<=heights[i];j++) {
//              record[j]++;
//            }
//          }
//          else{
//            for (int j=1;j<=heights[i];j++) {
//              record[j]++;
//            }

//            for (int j=heights[i]+1;j<=heights[i-1];j++) {

//              int tmp=j*record[j];
//              max=max>tmp?max:tmp;
//              record[j]=0;

//            }
//          }

//        }
//        /// 退出循环后可能有数据残留

//        for (int j=1;j<=heights[heights.size()-1];j++) {

//          int tmp=j*record[j];
//          max=max>tmp?max:tmp;
//          record[j]=0;
//        }
//        return max;
//      }

    /// 计算一个面积只需要知道长和高
    /// 用一个堆栈保存长和高
    ///  高度可以直接使用源数据中的，因此可以只记录位置
    /// 只需要记录前面都需要的数据
    /// 记录的数据形成的图形是阶梯状上升的，形成的矩形都是以台阶作为边界，而不必每次都进行计算

    int largestRectangleArea(vector<int>& heights)
    {
        int ans = 0;
        vector<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[st.back()] > heights[i])
            {
                int cur = st.back();
                st.pop_back();
                int left = st.back() + 1;
                int right = i - 1;
                ans = max(ans, (right - left + 1) * heights[cur]);
            }
            st.push_back(i);
        }
        return ans;
    }


  };




//  单调栈分为单调递增栈和单调递减栈
//  11. 单调递增栈即栈内元素保持单调递增的栈
//  12. 同理单调递减栈即栈内元素保持单调递减的栈

//  操作规则（下面都以单调递增栈为例）
//  21. 如果新的元素比栈顶元素大，就入栈
//  22. 如果新的元素较小，那就一直把栈内元素弹出来，直到栈顶比新元素小

//  加入这样一个规则之后，会有什么效果
//  31. 栈内的元素是递增的
//  32. 当元素出栈时，说明这个新元素是出栈元素向后找第一个比其小的元素

//      举个例子，配合下图，现在索引在 6 ，栈里是 1 5 6 。
//      接下来新元素是 2 ，那么 6 需要出栈。
//      当 6 出栈时，右边 2 代表是 6 右边第一个比 6 小的元素。

//      当元素出栈后，说明新栈顶元素是出栈元素向前找第一个比其小的元素

//      当 6 出栈时，5 成为新的栈顶，那么 5 就是 6 左边第一个比 6 小的元素。

//  代码模板

//  stack<int> st;
//  for(int i = 0; i < nums.size(); i++)
//  {
//    while(!st.empty() && st.top() > nums[i])
//    {
//      st.pop();
//    }
//    st.push(nums[i]);
//  }

//  画图理解
//  图片.png

//思路

//  对于一个高度，如果能得到向左和向右的边界
//  那么就能对每个高度求一次面积
//  遍历所有高度，即可得出最大面积
//  使用单调栈，在出栈操作时得到前后边界并计算面积

