//User function Template for C++

/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
    pair<int, int> solve(Node* root){
        if(!root) return {0, 0};
        
        auto lh = solve(root->left);
        auto rh = solve(root->right);
        
        int sum = root->data;
        
        if(lh.first == rh.first){
            sum += lh.second>rh.second ? lh.second : rh.second;
        }
        else if(lh.first > rh.first){
            sum += lh.second;
        }
        else{
            sum += rh.second;
        }
        
        return {max(lh.first, rh.first) + 1, sum};
        
    }
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        return solve(root).second;
    }
};