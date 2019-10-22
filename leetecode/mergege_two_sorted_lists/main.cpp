#include<iostream>
#include<string>
#include"merge_two_sorted_lists.hpp"
using namespace std;

int main(){
  Solution tmp;
  ListNode* list1_1=new ListNode(1);
  ListNode* list1_2=new ListNode(2);
  ListNode* list1_3=new ListNode(4);
  list1_1->next=list1_2;
  list1_2->next=list1_3;
  printlist(list1_1);
  ListNode* list2_1=new ListNode(1);
//  ListNode* list2_2=new ListNode(3);
  //ListNode* list2_3=new ListNode(4);
//  list2_1->next=list2_2;
//  list2_2->next=list2_3;
  printlist(list2_1);

  ListNode* reslist= tmp.mergeTwoLists(list1_1,list2_1);
  printlist(reslist);
  return 0;
}
