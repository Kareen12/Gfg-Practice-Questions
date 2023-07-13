//User function Template for C++

//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
    pair<int, int> solve(Node* root){
        if(!root) return {0,0};
        
        pair<int, int> leftAns = solve(root->left);
        pair<int, int> rightAns = solve(root->right);
        
        // When root node included
        int a = root->data + leftAns.second + rightAns.second;
        
        // When root node not included
        int b = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);
        return {a,b};
    }
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};