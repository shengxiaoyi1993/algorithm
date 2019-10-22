#include <iostream>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int len1=nums1.size();
      int len2=nums2.size();
      if((len1+len2)%2==0){
        //若为偶数,找到(n+m)/2,(n+m)/2+1,计算两者的平均

        int result[len1+len2];
        int k=0;
        int i=0;
        int j=0;


        while( i<len1 && j<len2 )
        {
            if( nums1[i] <= nums2[j] )
                result[k++] = nums1[i++];
            else
                result[k++] = nums2[j++];
        }
        /**nums1还有剩余**/
        while( i<len1 )
            result[k++] = nums1[i++];
        /**nums2还有剩余**/
        while( j<len2 )
            result[k++] = nums2[j++];

        return (result[(len1+len2)/2]+result[(len1+len2)/2+1])*1.0/2;


      }
      else{
        //若为奇数,找到（n+m+1）/2
        int result[len1+len2];
        int k=0;
        int i=0;
        int j=0;

        while( i<len1 && j<len2 )
        {
            if( nums1[i] <= nums2[j] )
                result[k++] = nums1[i++];
            else
                result[k++] = nums2[j++];
        }
        /**nums1还有剩余**/
        while( i<len1 )
            result[k++] = nums1[i++];
        /**nums2还有剩余**/
        while( j<len2 )
            result[k++] = nums2[j++];

        return (result[(len1+len2+1)/2])*1.0/2;
      }
    }
};
