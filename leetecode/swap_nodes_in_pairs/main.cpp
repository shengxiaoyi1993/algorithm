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

  list1_1->next=list1_2;
  list1_2->next=list1_3;
  list1_3->next=list1_4;

  printlist(list1_1);

  ListNode* list_re=tmp.swapPairs(list1_1);
  printlist(list_re);


  return 0;
}
