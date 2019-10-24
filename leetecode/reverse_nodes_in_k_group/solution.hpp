#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
 };
 void printlist(ListNode* head){
   ListNode* tmp=head;
   if(head == NULL){
     cout<<"list is null"<<endl;
     return;
   }
   for(;tmp!=NULL;tmp=tmp->next){
     cout<<tmp->val<<" ";
   }
   cout<<endl;
 }



 class Solution {
 public:
     ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* node_start=head;
       ListNode* node_end=NULL;
       ListNode* node_front=NULL;
       int value_run;
       bool flag_first=true;
       value_run=k;
       int size=countNodeListSize(head);
       int num_run=size/k;
       int count_run=0;
       while (k==value_run &&num_run>0) {
         value_run=swapKNodes(k,node_front,node_start,node_end);
         if(flag_first){
           head=node_start;
           flag_first=false;
         }
         num_run--;
       }


       return head;
     }
     int countNodeListSize(ListNode* head){
       int count=0;
       while(head !=NULL){
         head=head->next;
         count++;
       }
       return count;
     }


  int swapKNodes(int k, ListNode* &node_front, ListNode*  &node_start, ListNode* &node_end){
    ListNode* node_next= NULL;
    ListNode* node_helper= NULL;

    if(node_front == NULL){
      //first run

    }
    else{
      node_start = node_front->next;
    }
    if(node_start == NULL){
      return 0;
    }
    node_next =node_start->next;
    node_end = node_start;
    int count=1;
    while (count<k && node_next != NULL) {
      // cout<<"node_next:"<<node_next->val<<endl;
      // cout<<"node_start B:"<<node_start->val<<endl;

      node_helper = node_next->next;
      node_next->next=node_start;
      node_start=node_next;
      node_next=node_helper;
      // cout<<count<<" "<<endl;
      // cout<<"node_start A:"<<node_start->val<<endl;

      count++;
    }

    if(node_front != NULL){
      //not run
      node_front->next=node_start;
    }

    node_front=node_end;
    node_end->next=node_next;
    return count;
  }


 };
