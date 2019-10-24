#include<iostream>
#include<string>
#include"solution.hpp"
using namespace std;
int main(){
  Solution tmp;
  ListNode* list1_1=new ListNode(1);
  ListNode* list1_2=new ListNode(2);
  ListNode* list1_3=new ListNode(3);
  ListNode* list1_4=new ListNode(4);
  ListNode* list1_5=new ListNode(5);
  ListNode* list1_6=new ListNode(6);
  ListNode* list1_7=new ListNode(7);
  list1_1->next=list1_2;
  list1_2->next=list1_3;
  list1_3->next=list1_4;
  list1_4->next=list1_5;
  list1_5->next=list1_6;
  list1_6->next=list1_7;

ListNode* list_null=NULL;

  ListNode* list_res=tmp.reverseKGroup(list1_1,4);

  printlist(list_res);

  return 0;
}
