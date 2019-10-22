#include<iostream>
#include<string>
#include<vector>
#include"solution.hpp"
using namespace std;
int main(){
  ListNode* list1_1=new ListNode(1);
  ListNode* list1_2=new ListNode(2);
  ListNode* list1_3=new ListNode(3);
  ListNode* list1_4=new ListNode(4);
  ListNode* list1_5=new ListNode(5);
  list1_1->next=list1_2;
  list1_2->next=list1_3;
  list1_3->next=list1_4;
  list1_4->next=list1_5;
  Solution tmp;
tmp.removeNthFromEnd(list1_1,2);
printlist(list1_1);


  return 0;
}
