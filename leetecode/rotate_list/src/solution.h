#include <vector>
#include <iostream>
#include <vector>

using namespace std;




//61. Rotate List

//Given the head of a linked list, rotate the list to the right by k places.



//Example 1:

//Input: head = [1,2,3,4,5], k = 2
//Output: [4,5,1,2,3]

//Example 2:

//Input: head = [0,1,2], k = 4
//Output: [2,0,1]



//Constraints:

//    The number of nodes in the list is in the range [0, 500].
//    -100 <= Node.val <= 100
//    0 <= k <= 2 * 109


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

  ListNode* reset(const vector<int> & l_num)
  {
    ListNode *list = nullptr;
    ListNode *head = nullptr;

    for(auto it:l_num)
    {
      ListNode *tmpnode= new ListNode(it);
      if (list ==nullptr) {
        list=tmpnode;
        head=list;
      }
      else
      {
        list->next=tmpnode;
        list=list->next;
      }

    }
    return head;
  }

  void printList(ListNode* head)
  {
    ListNode* tmp=head;
    while (tmp!=nullptr) {
      std::cout<<tmp->val<<" ";
      tmp=tmp->next;
    }
    std::cout<<std::endl;
  }


  ListNode* rotateRight(ListNode* head, int k) {

    if (head==nullptr|| head->next==nullptr || k==0) {
      return head;
    }

    ListNode* startp=nullptr;

    ListNode* endrecord=nullptr;


    ListNode* it=head;
    int count=0;
    while (it->next != nullptr) {
      it=it->next;
      count++;
    }
    endrecord=it;


    k=k%(count+1);
    int remain=count+1-k;

    if (remain == 0) {
      return head;
    }


    it=head;
    for (int i=0;i<remain-1; i++) {
      it=it->next;
    }

    endrecord->next=head;
    startp =it->next;
    it->next=nullptr;

    return startp;



  }
};
