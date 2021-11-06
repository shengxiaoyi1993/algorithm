#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


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

//class Solution {

//  typedef  struct imp_node{
//    int __num;
//    bool __isStart;
//    imp_node(int v_num,bool v_isStart):__num(v_num),__isStart(v_isStart){}
//  } Node;


//public:





//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//      vector<Node> l_nodes;
//      if (intervals.size()>=0) {
//        l_nodes.push_back(Node(intervals[0][0],true));
//        l_nodes.push_back(Node(intervals[0][1],false));
//      }
//      else{
//        return {};
//      }
//      for (int i=1;i<intervals.size();i++) {
//        int num_start=intervals[i][0];
//        int num_end=intervals[i][1];
//        if (num_start == ) {

//        }

//        /// find a num biger or equal to num_start
//        auto pos_find=find_if(l_nodes.begin(),l_nodes.end(),[=](const Node& v_node  ){
//          return num_start<=v_node.__num;
//        });

//        if (pos_find == l_nodes.end()) {
//          l_nodes.push_back(Node(num_start,true));
//          l_nodes.push_back(Node(num_end,false));
//        }
//        else{
//          if (num_start!=pos_find->__num
//              &&(pos_find == l_nodes.begin()
//              || pos_find->__isStart==true )) {
//            ///if point_start is just following nothing/or point_end_, just insert it
//            l_nodes.insert(pos_find,Node(num_start,true));

//          }
//          else if(pos_find->__isStart==false
//                  || (num_start==pos_find->__num &&pos_find->__isStart==true)
//                  ){
//            /// >else if point_start following point_start_(alis as sh point_start__), \\
//            /// or equals point_start_, not insert it
//          }
//          else if(pos_find->__isStart == false
//                  && pos_find->__num==num_start){
//            /// >else if point_start equals point_end_, remove it ,
//          }
//          else
//          {
//            std::cout<<"other num_start conditions"<<std::endl;
//          }

//        }


//      }



//    }

/// solution2 //if  interval all in another intervals
/// map point_end in list
/// compare point_start with other point in list
/// >if  in range of other intervals ,merge two ,do map continue
/// >if not in range of other intervals,compare next
/// End when all point is map

/// solution 3
/// map point in list
/// try to merge two intervals, set first interval as inter_p
/// >if merge succeed,rm the the second interval
/// >if not merge succeed,
/// >>if remain interval in list ,set next interval as inter_s,repeat
/// >>if no remain interval in list,
/// >> try change a inter_p,
/// >>> if set a new inter_p,continue
/// >>> if not set a new inter_p,end

class Solution {

public:
  /// if merge succeed just do change in intervals, merge and remove another
  ///
  bool mergeTwo(vector<vector<int>>& intervals,int v_seq_p,int v_seq_s)
  {
    if ((intervals[v_seq_p][1]>=intervals[v_seq_s][0]
         &&intervals[v_seq_p][1]<=intervals[v_seq_s][1])
        ||(intervals[v_seq_s][1]>=intervals[v_seq_p][0]
           &&intervals[v_seq_s][1]<=intervals[v_seq_p][1])
        )
    {
      intervals[v_seq_p][0]=intervals[v_seq_p][0]<intervals[v_seq_s][0]
          ?intervals[v_seq_p][0]:intervals[v_seq_s][0];
      intervals[v_seq_p][1]=intervals[v_seq_p][1]>intervals[v_seq_s][1]
          ?intervals[v_seq_p][1]:intervals[v_seq_s][1];
      intervals.erase(intervals.begin()+v_seq_s);
      return true;
    }
    return false;

  }

  ///
//  vector<vector<int>> merge(vector<vector<int>>& intervals) {
//    vector<vector<int>> l_ret;

//    for (int i=0;i<intervals.size()-1;i++) {
//      bool change=false;
//      for (int j=i+1;j<intervals.size();j++) {
//        int bret = false;

//        if ((intervals[i][1]>=intervals[j][0]
//             &&intervals[i][1]<=intervals[j][1])
//            ||(intervals[j][1]>=intervals[i][0]
//               &&intervals[j][1]<=intervals[i][1])
//            )
//        {
//          intervals[i][0]=intervals[i][0]<intervals[j][0]
//              ?intervals[i][0]:intervals[j][0];
//          intervals[i][1]=intervals[i][1]>intervals[j][1]
//              ?intervals[i][1]:intervals[j][1];
//          intervals.erase(intervals.begin()+j);
////          return true;
//          bret=true;
//        }


//        if (bret == true) {
//          change =true;
//          j--;
//        }
//      }
//      if (change == true ) {
////        std::cout<<"i:"<<i<<std::endl;
//        i--;
//      }
//    }
//    //   l_ret=intervals;
//    return intervals;
//  }

/// use map to deal with it
/// put all element to map<int,int> ,first is the position,second is count
/// map all pair in map<>,if value == 0, save it;and save the first not 0

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      std::map<int,int> m_ele;
      for (auto it:intervals) {
        if (m_ele.find(it[0]) == m_ele.end() ) {
          m_ele[it[0]]=1;
        }
        else{
          m_ele[it[0]]++;
        }

        if (m_ele.find(it[1]) == m_ele.end() ) {
          m_ele[it[1]]=-1;
        }
        else{
          m_ele[it[1]]--;
        }
      }

//      for (auto it:m_ele) {
//        std::cout<<it.first<<":"<<it.second<<std::endl;
//      }

       vector<vector<int>> l_ret;
       int count=0;
       bool has_front=false;

       /// if no point_start before,push a new intervals,and set this point as point_start
       /// when sum == 0,it should be the point_end
       for (auto it:m_ele) {
         count+=it.second;

         if (!has_front) {
           l_ret.push_back({it.first,0});
           has_front=true;
         }

         if (count == 0) {
           l_ret[l_ret.size()-1][1]=it.first;
           has_front=false;
         }
       }


       return l_ret;

    }


};
