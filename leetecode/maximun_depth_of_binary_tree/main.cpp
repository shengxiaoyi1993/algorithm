#include<iostream>
#include<string>
#include"solution.hpp"
using namespace std;
int main(){
  TreeNode *head1=new TreeNode(1);
  head1->left=new TreeNode(2);
  head1->right=new TreeNode(3);
  head1->left->left=new TreeNode(2);

  Solution tmp;
  cout<<tmp.maxDepth(head1);
  return 0;
}
