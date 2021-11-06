#include <vector>
#include <iostream>
#include <vector>

using namespace std;


//82. Remove Duplicates from Sorted List II

//Given the head of a sorted linked list, delete all nodes that have duplicate numbers,
//leaving only distinct numbers from the original list. Return the linked list sorted as well.



//Example 1:

//Input: head = [1,2,3,3,4,4,5]
//Output: [1,2,5]

//Example 2:

//Input: head = [1,1,1,2,3]
//Output: [2,3]

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

  /// 一个元素记录前一个值，和该值是否有效
  /// 一个值记录有效长度
  /// 逐个遍历所有的元素
  /// 若当前元素与前一个元素相同，设置记录有效，跳过
  /// 若当前元素与前一个不同，
  /// >且历史值无效，跳过
  /// >及历史值有效，有效长度++，
  /// 更改记录值，设置记录有效
  ///
  /// 删除有效长度外的

  ListNode* deleteDuplicates(ListNode* head) {

    if (head == nullptr) {
      return nullptr;
    }

    /// 指向有效的最后一个元素或null
    ListNode* help=nullptr;
    bool record_valid=true;
    int  num_record=head->val;

    ListNode* item=head->next;

    while (item != nullptr) {
      if (num_record == item->val) {
        record_valid=false;
      }
      else{
        if (record_valid) {
          if (help == nullptr) {
            help=head;
          }
          else{
            help=help->next;
          }
          help->val=num_record;
          num_record=item->val;
        }
        else{
          num_record=item->val;
          record_valid=true;
        }

      }

      item=item->next;
    }

    /// 处理最后一个元素
    if (record_valid) {
      if (help == nullptr) {
        help=head;
      }
      else{
        help=help->next;
      }
      help->val=num_record;
    }

    ///删除无效长度
    if (help == nullptr) {
      return nullptr;
    }
    else{
      help->next=nullptr;
      return head;
    }

  }
};
