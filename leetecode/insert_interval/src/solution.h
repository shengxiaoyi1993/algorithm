#include <vector>
#include <iostream>

using namespace std;


//57. Insert Interval

//You are given an array of non-overlapping intervals intervals where intervals[i]
//= [starti, endi] represent the start and the end of the ith interval and
//intervals is sorted in ascending order by starti. You are also given
//an interval newInterval = [start, end] that represents the start and end of another interval.

//Insert newInterval into intervals such that intervals is still sorted in
//ascending order by starti and intervals still does not have any overlapping
//intervals (merge overlapping intervals if necessary).

//Return intervals after the insertion.



//Example 1:

//Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
//Output: [[1,5],[6,9]]

//Example 2:

//Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
//Output: [[1,2],[3,10],[12,16]]
//Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

//Example 3:

//Input: intervals = [], newInterval = [5,7]
//Output: [[5,7]]

//Example 4:

//Input: intervals = [[1,5]], newInterval = [2,3]
//Output: [[1,5]]

//Example 5:

//Input: intervals = [[1,5]], newInterval = [2,7]
//Output: [[1,7]]



//Constraints:

//    0 <= intervals.length <= 104
//    intervals[i].length == 2
//    0 <= starti <= endi <= 105
//    intervals is sorted by starti in ascending order.
//    newInterval.length == 2
//    0 <= start <= end <= 105

/// because in ascending order and no overlap
/// find the point_* no smaller than newInterval_start,
/// and point_* no smaller than newInterval_end
///
/// just gradually insert every element in intervals to new ,to the end
/// or merge with the end


/// gradually insert all ,to new
/// just consider the last ,merge with last or insert before or follow the end
///


class Solution {
public:


  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval)
  {

    vector<vector<int>>  l_new;
    bool noverlap;
    l_new.push_back(newInterval);
    for (auto it:intervals)
    {
      if (noverlap == true)
      {
        l_new.push_back(it);
      }
      else
      {
        vector<int> last_in_new=l_new[l_new.size()-1];
        if (it[1]<last_in_new[0]) {
          l_new.insert(l_new.end()-1,it);
        }
        else if(last_in_new[1]<it[0]){
          l_new.insert(l_new.end(),it);
          noverlap =true;
        }
        else{
          int start=last_in_new[0]<it[0]?last_in_new[0]:it[0];
          int end=last_in_new[1]>it[1]?last_in_new[1]:it[1];
          l_new[l_new.size()-1]={start,end};
        }
      }
    }
    return l_new;
  }
};


