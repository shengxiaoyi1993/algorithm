#include "solution.h"

int main(int argc, char const *argv[])
{
    Solution tmp;
    ListNode* list=tmp.reset({0,1,2});
    tmp.printList(list);
    tmp.printList(list);

    ListNode* ret=tmp.rotateRight(list,4);
    tmp.printList(ret);


    
    return 0;
}

