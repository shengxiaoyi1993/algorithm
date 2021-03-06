#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
      if(p==NULL&&q==NULL){
        return true;
      }
      else if(p==NULL&&q!=NULL){
        return false;
      }
      else if(p!=NULL&&q==NULL){
        return false;
      }
      else{
        if(p->val==q->val&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right)){
          return true;
        }
        else{
          return false;
        }
      }
    }

    int maxDepth(TreeNode* root) {
      if(root==NULL){
        return 0;
      }
      else{
        int count_left=maxDepth(root->left);
        int count_right=maxDepth(root->right);
        return ((count_left>count_right)?count_left:count_right)+1;
      }
    }
};
