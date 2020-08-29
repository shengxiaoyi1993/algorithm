# design

## demand
- 设计基本树的类，满足树的条件
  - 子节点： 包含0个或者多个子节点
  - 父节点： 唯一没有父节点的是根节点
  - 子树，以子节点为根结点可以拆分成不同子树，子树不相交
- 支持不同的类型
- 方便拓展

## design
### struct

```cpp
template <typename T>
class TreeNode{
  TreeNode* _pfather;
  vector<TreeNode*> _pchild;
  T _data;
}

template <typename T>
class Tree{
  TreeNode* _father;
  int append(const T& v_data);
  void print();
}

```

### Interface
-

## relize
