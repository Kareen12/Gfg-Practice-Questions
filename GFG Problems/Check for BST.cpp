class Solution
{
    bool solve(Node* root, long lb, long ub){
        if(!root) return true;

        if(root->data >lb && root->data < ub){
            bool leftAns = solve(root->left, lb, root->data);
            bool rightAns = solve(root->right, root->data, ub);
            return leftAns && rightAns;
        }
        else{
            return false;
        }
    }
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        return solve(root, LONG_MIN, LONG_MAX);
    }
};

