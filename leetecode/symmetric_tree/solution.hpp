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
        if(p->val==q->val&&isSameTree(p->left,q->left)
        &&isSameTree(p->right,q->right)){
          return true;
        }
        else{
          return false;
        }
      }
    }


    bool isSymmetric(TreeNode* root) {
      TreeNode* tmp=ChangeToSymmetric(root);
      return isSameTree(tmp,root);
    }


    TreeNode* ChangeToSymmetric(TreeNode* root) {
      if(root==NULL){
        return NULL;
      }
      else{
        TreeNode* tmp=new TreeNode(root->val);
        tmp->left=ChangeToSymmetric(root->right);
        tmp->right=ChangeToSymmetric(root->left);
        return tmp;
      }
    }


};
