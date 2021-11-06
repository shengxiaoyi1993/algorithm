#include "solution.h"

int main(int argc, char const *argv[])
{
    Solution tmp;

//    vector<int> nums={1,2,3,3,4,4,5};
    vector<int> nums={1,1,1,2,3};


    ListNode * head = new ListNode(nums[0]);
    ListNode * help= head;

    for (size_t i=1;i<nums.size();i++) {
      ListNode * tmp = new ListNode(nums[i]);
      help->next=tmp;
      help=tmp;
    }


   auto ret= tmp.deleteDuplicates(head);

    help =ret;
   while (help!=nullptr) {
     std::cout<<help->val<<" ";
     help=help->next;
   }
   std::cout<<endl;


    
    return 0;
}
