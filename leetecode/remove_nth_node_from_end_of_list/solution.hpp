#include<iostream>
#include<string>
#include<vector>

using namespace std;

//  Definition for singly-linked list.
  struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  void printlist(ListNode* head){
    ListNode* tmp=head;
    for(;tmp!=NULL;tmp=tmp->next){
      cout<<tmp->val<<" ";
    }
    cout<<endl;
  }


class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* head_target_front = head;
        ListNode* node_patrol=head;


          for(int i=0;i<n;i++){
            if( node_patrol != NULL ){
                node_patrol=node_patrol->next;
            }
            else{
                break;
            }
        }

        if(node_patrol == NULL){
            return head->next;
        }
        else{
          while(node_patrol->next != NULL){
            node_patrol = node_patrol->next;
            head_target_front= head_target_front->next;
        }

        if(head_target_front !=NULL){
          if(head_target_front->next !=NULL){
            head_target_front->next=head_target_front->next->next;
          }
        }
        }

        return head;

    }
};
