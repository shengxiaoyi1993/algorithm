#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>

using namespace std;


template <typename T>
class TreeNode{
  TreeNode* _pfather;
  vector<TreeNode*> _pchildlist;
  T _data;
};

template <typename T>
class Tree{
  TreeNode<T>* _father;
  int append(const T& v_data);
  void print();
};


#endif // TREE_H
