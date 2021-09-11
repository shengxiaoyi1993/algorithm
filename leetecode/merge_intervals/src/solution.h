#include <vector>
#include <iostream>
#include <vector>

using namespace std;

//56. Merge Intervals

//Given an array of intervals where intervals[i] = [starti, endi], merge all \\
//overlapping intervals, and return an array of the non-overlapping intervals \\
//that cover all the intervals in the input.


//Example 1:

//Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
//Output: [[1,6],[8,10],[15,18]]
//Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

//Example 2:

//Input: intervals = [[1,4],[4,5]]
//Output: [[1,5]]
//Explanation: Intervals [1,4] and [4,5] are considered overlapping.



//Constraints:

//    1 <= intervals.length <= 104
//    intervals[i].length == 2

//    0 <= starti <= endi <= 104


/// alist of (int, bool)point
/// asumme point in list is all right
/// so all point is coupled and is cross arranged
///
/// when one point wait to be inserted,seach for position
/// >if point_start is just following nothing/or point_end_, just insert it
/// >>then find the point_end position,
/// >>>if just follow  point_start,just insert it
/// >>>this is some point between point_start and point_end,
/// >>>>if followd point_start_,remove all point_between_ and not insert point_end
/// >>>>if followed point_end_,remove all point_between_ and inset point_end
/// >else if point_start following point_start_(alis as sh point_start__), \\
/// or equals point_start_, not insert it
/// >>if follow point_start_,remove between point_start__ and not insert
/// >>if follow point_end_,remove between point_start__ and insert
/// >else if point_start equals point_end_, remove it ,
/// >> if point_end follows point_end_, remove all point between point_start and insert
/// >> else if point_end follows point_start_,remove all point between point_start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

    }
};