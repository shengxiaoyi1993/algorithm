#include <vector>
#include <iostream>
#include <vector>

using namespace std;



//71. Simplify Path

//Given a string path, which is an absolute path (starting with a slash '/')
//to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

//In a Unix-style file system, a period '.' refers to the current directory,
//a double period '..' refers to the directory up a level,
//and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'.
//For this problem, any other format of periods such as '...' are treated as file/directory names.

//The canonical path should have the following format:

//    The path starts with a single slash '/'.
//    Any two directories are separated by a single slash '/'.
//    The path does not end with a trailing '/'.
//    The path only contains the directories on the path from the root directory
//to the target file or directory (i.e., no period '.' or double period '..')

//Return the simplified canonical path.



//Example 1:

//Input: path = "/home/"
//Output: "/home"
//Explanation: Note that there is no trailing slash after the last directory name.

//Example 2:

//Input: path = "/../"
//Output: "/"
//Explanation: Going one level up from the root directory is a no-op,
//as the root level is the highest level you can go.

//Example 3:

//Input: path = "/home//foo/"
//Output: "/home/foo"
//Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.

//Example 4:

//Input: path = "/a/./b/../../c/"
//Output: "/c"



//Constraints:

//    1 <= path.length <= 3000
//    path consists of English letters, digits, period '.', slash '/' or '_'.
//    path is a valid absolute Unix path.

/// 以一个堆栈保存结果
/// 依次识别字符，以模式单元进行操作
/// >纯. 删除堆栈中之前的项
/// >/* 分隔项
/// >其他 加入堆栈
/// 完成所有后将堆中数据

/// 将所有连在一起的/替换成 '/'
/// /分隔字符串
/// 采用


/// 以'/'作为分隔符对字符串进行处理
/// 逐个字节进行识别
/// '/' ： 起始 多余的 终止 ：
///  >当没有保存数据时不做处理
///  > 当保存的是'.',不做处理
///  > 当保存的是'..',删除栈中的最后一项
///  > 当保存的是其他，则在将该项加入栈中，因此需要保存具体字符，就根据起始位置与长度来截取
///  清空临时数据
/// '.' :
///  >若midtype==0
/// 则midtype=1否则不变,dot_count++,segment_start=pos_cur
///
///
/// 'other':
///  >midtype=2,
///  > if midtype==0,segment_start=pos_cur


class Solution {
public:

    string simplifyPath(string path) {
      vector<string> stack;
      path+="/";
      path[0];
      int length=path.length();

      /// 0 无
      /// 1 纯.
      /// 2 validpath
      int midtype=0;
      int segment_start=-1;

      for (int i=0;i<length;i++) {
        switch (path[i]) {
          case '/':
          {
            if (midtype == 1)
            {
              /// 计算'.'的数量
              if (i - segment_start == 1) {

              }
              else if(i - segment_start == 2)
              {
//                stack.erase(stack.end());
                if (stack.size()>=1) {
                  stack.pop_back();
                }
              }
              else{
                stack.push_back(path.substr(segment_start,i - segment_start));
              }
            }
            else if(midtype == 2)  {
              stack.push_back(path.substr(segment_start,i - segment_start));
            }

            midtype = 0;
            break;
          }
          case '.':
          {
            if (midtype ==0) {
              midtype=1;
              segment_start =i;
            }
            break;
          }
          default:
          {
            if (midtype == 0) {
              segment_start =i;
            }
            midtype = 2;
          }
        }

      }

      /// combine the string
      string ret;

      if (stack.size() == 0) {
        ret="/";
      }
      else{
        for (auto it:stack) {
          ret+="/"+it;
        }
      }

      return ret;
    }
};


//class Solution {
//public:
//    string simplifyPath(string path) {
//        for(int i = 0; i < path.size(); ++i){
//            if(i >= 0 && path[i] == '/' && path[i + 1] == '.' && path[i + 2] == '.' && (i + 3 == path.size() || path[i + 3] == '/')){
//                if(i == 0){
//                    path.erase(i + 1, 2);
//                    i = -1;
//                }
//                else{
//                    int k = i - 1;
//                    while(path[k] != '/'){
//                        --k;
//                    }
//                    path.erase(k + 1, i - k + 2);
//                    i = k - 1;
//                }
//            }

//            if(i >= 0 && path[i] == '/' && path[i + 1] == '.' && (i + 2 == path.size() || path[i + 2] == '/')){
//                if(i == 0){
//                    path.erase(i + 1, 1);
//                    i = -1;
//                }
//                else{
//                    path.erase(i, 2);
//                    i = i - 1;
//                }
//            }

//            if(i >= 0 && path[i] == '/' && path[i+1] == '/'){
//                path.erase(i, 1);
//                i = i - 1;
//            }
//        }
//        if(path.size() >= 2 && path[path.size() - 1] == '/'){
//            path.pop_back();
//        }

//        return path;
//    }
//};

