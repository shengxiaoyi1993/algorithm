#include<iostream>
#include<string>
#include<vector>
#include"solution.hpp"
using namespace std;
int main(){
  Solution tmp;
  ListNode* list1_1=new ListNode(1);
  ListNode* list1_2=new ListNode(4);
  ListNode* list1_3=new ListNode(5);
  list1_1->next=list1_2;
  list1_2->next=list1_3;

  ListNode* list2_1=new ListNode(1);
  ListNode* list2_2=new ListNode(3);
  ListNode* list2_3=new ListNode(4);
  list2_1->next=list2_2;
  list2_2->next=list2_3;

  ListNode* list3_1=new ListNode(2);
  ListNode* list3_2=new ListNode(6);
  list3_1->next=list3_2;

  std::vector<ListNode*> list_total;
  list_total.push_back(list1_1);
  list_total.push_back(list2_1);
  list_total.push_back(list3_1);

  ListNode* res_list=tmp.mergeKLists(list_total);
  printlist(res_list);






  return 0;
}
