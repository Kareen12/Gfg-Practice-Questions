/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    pair<bool, int> solve(Node* root){
         if(root == NULL){
             pair<bool, int> p = make_pair(true, 0);
             return p;
         }
         if(root->left == NULL && root->right == NULL){
             pair<bool, int> p = make_pair(true, root->data);
             return p;
         }
         
         pair<bool, int> leftSum = solve(root->left);
         pair<bool, int> rightSum = solve(root->right);
         
         bool left = leftSum.first;
         bool right = rightSum.first;
         
         int leftKaSum = leftSum.second;
         int rightKaSum = rightSum.second;
         
         bool sum = root->data == leftKaSum + rightKaSum;
         
         pair<bool, int> ans;
         
         if(left && right && sum){
             ans.first = true;
             ans.second = root->data + leftKaSum + rightKaSum;
         }
         else{
             ans.first =  false;
         }
         return ans;
    }
    
    public:
    bool isSumTree(Node* root)
    {
         // Your code here
         return solve(root).first;
    }
};