#include<iostream>
#include<string>
#include"solution.hpp"
using namespace std;
int main(){
  Solution obj;
  ListNode *tmplist=new ListNode(1);
  ListNode *head=tmplist;
  ListNode *tmp=new ListNode(1);
  tmplist->next=tmp;
  tmplist=tmplist->next;
  ListNode *tmp1=new ListNode(2);
  tmplist->next=tmp1;
  tmplist=tmplist->next;
  ListNode *tmp2=new ListNode(3);
  tmplist->next=tmp2;
  tmplist=tmplist->next;
  ListNode *tmp3=new ListNode(3);
  tmplist->next=tmp3;
  tmplist=tmplist->next;
  printlist(head);
  ListNode *res_list=obj.deleteDuplicates(head);
  printlist(res_list);
  return 0;
}
