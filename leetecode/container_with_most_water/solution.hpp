#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:

    // int maxArea(vector<int>& height) {
    //   int area_max=0;
    //     for(int i=0;i<height.size();i++){
    //       for(int j=i+1;j<height.size();j++){
    //         int tmp_height=height[i]<height[j]?height[i]:height[j];
    //         int tmp_area=tmp_height*(j-i);
    //         area_max=tmp_area>area_max?tmp_area:area_max;
    //       }
    //     }
    //     return area_max;
    // }
    int maxArea(vector<int>& height) {
      int area_max=0;
      int len_height=height.size();

        for(int i=0;i<len_height;i++){
          int tmp_max_height=0;
          for(int j=len_height-1;j>i;j--){
            if(height[j]>tmp_max_height){
              int tmp_height=height[i]<height[j]?height[i]:height[j];
              int tmp_area=tmp_height*(j-i);
              area_max=tmp_area>area_max?tmp_area:area_max;
              tmp_max_height=height[j];
            }
          }
        }
        return area_max;
    }
};
