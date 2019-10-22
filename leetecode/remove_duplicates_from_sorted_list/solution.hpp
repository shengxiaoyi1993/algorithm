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
  ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL)
      return head;
   else{
    ListNode* newlist=new ListNode(head->val);
    ListNode* res_head=newlist;
    while(head!=NULL){
      if(newlist->val==head->val){
        head=head->next;
      }
      else{
        ListNode* tmplist=new ListNode(head->val);
        newlist->next=tmplist;
        newlist=newlist->next;
        head=head->next;
      }
    }
    return res_head;
  }
}
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      int first_time=1;
      ListNode* newlist=new ListNode(0);
      ListNode* head=newlist;
      while(!(l1==NULL&&l2==NULL)){
    //    printlist(head);
        if(l1!=NULL&&l2!=NULL){
          if(l1->val<l2->val){
            if(first_time){
              newlist->val=l1->val;
              first_time=0;
            }
            else{
              ListNode* tmplist=new ListNode(l1->val);
              newlist->next=tmplist;
              newlist=newlist->next;
            }
            l1=l1->next;
          }
          else{
            if(first_time){
              newlist->val=l2->val;
              first_time=0;

            }
            else{
              ListNode* tmplist=new ListNode(l2->val);
              newlist->next=tmplist;
              newlist=newlist->next;
            }
            l2=l2->next;

         }
        }
        else if(l1!=NULL&&l2==NULL){
          if(first_time){
            newlist->val=l1->val;
            first_time=0;

          }
          else{
            ListNode* tmplist=new ListNode(l1->val);
            newlist->next=tmplist;
            newlist=newlist->next;
          }
          l1=l1->next;
        }
        else if(l1==NULL&&l2!=NULL){
          if(first_time){
            newlist->val=l2->val;
            first_time=0;

          }
          else{
            ListNode* tmplist=new ListNode(l2->val);
            newlist->next=tmplist;
            newlist=newlist->next;
          }

          l2=l2->next;
        }
        else{
          if(first_time){
            return NULL;
          }
          else{
            return head;
          }

        }
      }
      return head;
    }
};
