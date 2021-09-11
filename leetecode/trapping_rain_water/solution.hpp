//
// 42. Trapping Rain Water
//
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//
// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
//
// Example:
//
// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
//


//思路
//排序
//由一列表记录已经填充的位置
//以最长为基，其他的数分别与该峰高进行比较，
// 若该峰未被填充，计算最近距离的被填充的峰与该峰的高度差，然后进行逐列填充，标记已填充列，记录填充的快的数量
// 若该峰被填充，继续


//他人思路
// 填充一些数字保证数组的单调性，以最高峰为界，左边非减，右边非增
//步骤
// 计算最大值位置
// 以最左侧点作为起点，定义tmp_l=height[0],sum=0,比较tmp_l与当前峰高,右移直到最高峰
//  若tmp_l>当前峰高,sum+=差值
//  若tmp_l<当前峰高,tmp_l=当前峰高
// 以最右侧作为起点，定义tmp_l=height[size-1],比较tmp_l与当前峰高,左移直到最高峰
//  若tmp_l>当前峰高,sum+=差值
//  若tmp_l<当前峰高,tmp_l=当前峰高
// 输出sum

// {
//   //
//   // class Solution {
//   // public:
//   //     //以最大值分界，左边非减，右边非增
//   //     int trap(vector<int>& height) {
//   //         int n=height.size();
//   //         if(n==0) return 0;
//   //         int m=max_element(height.begin(),height.end())-height.begin();
//   //         //遍历最大值左边
//   //         int res=0,cur=height[0];
//   //         for(int i=1;i<m;i++)
//   //         {
//   //             if(height[i]<cur)
//   //                 res+=cur-height[i];
//   //             else
//   //                 cur=height[i];
//   //         }
//   //         //遍历最大值右边
//   //         cur=height[n-1];
//   //         for(int i=n-2;i>m;i--)
//   //         {
//   //             if(height[i]<cur)
//   //                 res+=cur-height[i];
//   //             else
//   //                 cur=height[i];
//   //         }
//   //         return res;
//   //     }
//   // };
//
// }


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:


  int trap(vector<int>& height) {
    int height_size=height.size();
    if(height_size<=1){
      return 0;
    }
    //计算pos_max
    int pos_max=max_element(height.begin(),height.end())-height.begin();
    //left
    int sum=0;
    int tmp_left=height[0];
    for (size_t i = 1; i < pos_max; i++) {
      if(height[i]<tmp_left){
        sum+=(tmp_left-height[i]);
      }
      else if(height[i]>tmp_left){
        tmp_left=height[i];
      }
    }

//right
    int tmp_right=height[height_size-1];
    for (size_t i = height_size-1; i > pos_max; i--) {
      if(height[i]<tmp_right){
        sum+=(tmp_right-height[i]);
      }
      else if(height[i]>tmp_right){
        tmp_right=height[i];
      }
    }
    return sum;

  }

//   int getSeq(vector<int> nums,vector<int>& seqs){
//     int tmp=0;
//     int tmpseq=0;
//     size_t size_nums=nums.size();
//     seqs.resize(size_nums);
//
//     for(size_t i=0;i<size_nums;i++){
//         seqs[i]=i;
//     }
//     for(size_t i=0;i<size_nums;i++){
//         for(size_t j=0;j<size_nums-i-1;j++){
//             if(nums[j]<nums[j+1]){
//                 tmp=nums[j];
//                 nums[j]=nums[j+1];
//                 nums[j+1]=tmp;
//                 tmpseq=seqs[j];
//                 seqs[j]=seqs[j+1];
//                 seqs[j+1]=tmpseq;
//             }
//         }
//     }
//     return 0;
//
// }
//
//
//
//     int trap(vector<int>& height) {
//       int sum=0;
//       vector<int> flags;
//       int height_size=height.size();
//       if(height_size <=0){
//         return 0;
//       }
//       flags.resize(height_size);
//       for (size_t i = 0; i < height_size; i++) {
//         flags[i]=0;
//       }
//
//       vector<int> tmpheight=height;
//       vector<int> post;
//       getSeq(tmpheight,post);
//
//       // for (size_t i = 0; i < post.size(); i++) {
//       //   std::cout <<post[i] <<" ";
//       // }
//
//       flags[post[0]]=1;
//
//       //计算
//       for (size_t i = 1; i < height_size; i++) {
//         if(post[i]>=post[0]){
//           for (size_t j = post[i]; j >= post[0]; j--) {
//             if(flags[j]!=1){
//               sum+=height[post[i]]-height[j];
//               // std::cout << "sum:" <<sum<< '\n';
//
//               flags[j]=1;
//             }
//             else{
//               break;
//             }
//           }
//         }
//         else{
//             for (size_t j = post[i]; j <= post[0]; j++) {
//               if(flags[j]!=1){
//                 sum+=height[post[i]]-height[j];
//                 // std::cout << "sum:" <<sum<< '\n';
//
//                 flags[j]=1;
//               }
//               else{
//                 break;
//               }
//             }
//
//       }
//       // std::cout << "post[i]:" <<post[i]<< '\n';
//       // std::cout << "post[0]:" <<post[0]<< '\n';
//       // std::cout << "sum:" <<sum<< '\n';
//
//     }
//       return sum;
//     }
};
