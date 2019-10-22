#include<iostream>
#include<string>
#include"solution.hpp"
using namespace std;
int main(){
  TreeNode *head1=new TreeNode(1);
  head1->left=new TreeNode(2);
  head1->right=new TreeNode(3);
  TreeNode *head2=new TreeNode(1);
  head2->left=new TreeNode(3);
  head2->right=new TreeNode(2);

  Solution tmp;
  cout<<tmp.isSameTree(head1,head2);
  return 0;
}
