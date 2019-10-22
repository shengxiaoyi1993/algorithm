#include <iostream>
using namespace std;

 // Definition for singly-linked list.
struct ListNode {
        int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 class Solution {
 public:

     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

       ListNode * tmplist=new ListNode(0);
       ListNode * reslist=tmplist;

       int reminder=0;
       while(l1!=NULL&&l2!=NULL){
         int tmpnum=l1->val+l2->val+reminder;
         reminder=tmpnum/10;
         tmplist->next=new ListNode(tmpnum%10);
         l1=l1->next;
         l2=l2->next;
           tmplist=tmplist->next;
       }
      while(l1!=NULL){
         tmplist->next=new ListNode((l1->val+reminder)%10);
         reminder=((l1->val+reminder)/10);
         l1=l1->next;
          tmplist=tmplist->next;

       }
       while(l2!=NULL){
         tmplist->next=new ListNode((l2->val+reminder)%10);
               reminder=((l2->val+reminder)/10);

           l2=l2->next;
           tmplist=tmplist->next;
       }
 if(reminder!=0){
         tmplist->next=new ListNode(reminder);

 }
         return reslist->next;

     }

 };
