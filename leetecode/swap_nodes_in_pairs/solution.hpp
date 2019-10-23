#include <iostream>
using namespace std;
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
    ListNode* swapPairs(ListNode* head) {
      ListNode* help=NULL;
      ListNode*  front=NULL;
      ListNode* head_res=NULL;

      bool flag_firsttime=true;


      while (head != NULL) {
        if(head->next !=NULL){
          if( front == NULL){
            head_res=head->next;
          }
          help=head->next->next;
          head->next->next=head;
          if(flag_firsttime){
            flag_firsttime=false;
          }
          else{
            front->next=head->next;
          }
          head->next=help;

          front=head;
          head=front->next;

        }
        else{
          if( front == NULL){
            head_res=head;
          }
          break;
        }
        printlist(head_res);
      }

      return head_res;

    }
};
