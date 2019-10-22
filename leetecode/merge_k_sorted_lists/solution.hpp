#include <iostream>
#include<vector>
#include<string>
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

  bool isAllNull(vector<ListNode*>& lists){
    for(int i=0;i<lists.size();i++){
      if(lists[i] != NULL){
        return false;
      }
    }
    return true;
  }

  int returnMinAndDel(vector<ListNode*>& lists){
    bool falg_init=false;
    int count_list=0;
    int val_tmp;
    for(int i=0;i<lists.size();i++){
      if(lists[i] != NULL){
        if(!falg_init ){
          val_tmp=lists[i]->val;
          falg_init =true;
          count_list=i;
        }
        else{
          if(val_tmp>lists[i]->val){
            val_tmp=lists[i]->val;
            count_list=i;
          }
        }
      }
    }

    if(lists[count_list]!=NULL){
      lists[count_list]=lists[count_list]->next;
    }
    else{
      cout<<"error unexpect"<<endl;
    }
    return val_tmp;



  }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
      ListNode* head_res=NULL;
      ListNode* head=NULL;


      while(!isAllNull(lists)){
        int val=returnMinAndDel(lists);
        if(head_res == NULL){
          head_res=new  ListNode(val);
          head=head_res;
        }
        else{
          head_res->next=new ListNode(val);
          head_res=head_res->next;
        }
      }
      return head;
    }

    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //
    //   int size=lists.size();
    //   int count_sub;
    //   while (size>1) {
    //     for(int i=0;i<size/2;i++){
    //       lists[i]=mergeTwoLists(lists[i*2],lists[i*2+1]);
    //     }
    //     count_sub=size/2;
    //     if(size%2 == 1 ){
    //       lists[size/2]=lists[size-1];
    //       count_sub=size/2+1;
    //
    //     }
    //
    //       lists.erase(lists.begin()+count_sub,lists.end());
    //       size=lists.size();
    //
    //
    //   }
    //   if(isAllNull(lists) ){
    //     return NULL;
    //   }
    //   else{
    //     return lists[0];
    //   }
    //
    // }



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
