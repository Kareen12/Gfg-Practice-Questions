//User function template for C++

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
  int solve(Node* node){
      if(!node) return 0;
      
      if(!node->left && !node->right){
          int temp = node->data;
          node->data = 0;
          return temp;
      }
      int l = solve(node->left);
      int r = solve(node->right);
      int temp = node->data;
      node->data = l + r;
      return node->data + temp;
  }
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        // Your code here
        solve(node);
    }
};