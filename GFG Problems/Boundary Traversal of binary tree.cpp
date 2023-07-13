/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    void leftBoundary(Node *root, vector <int> &ans){
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL){
            return;
        }
        
        ans.push_back(root->data);
        if(root->left){
            leftBoundary(root->left, ans);
        }
        else{
            leftBoundary(root->right, ans);
        }
    }
    
    void leafBoundary(Node *root, vector <int> &ans){
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        
        leafBoundary(root->left, ans);
        leafBoundary(root->right, ans);
    }
    
    void rightBoundary(Node *root, vector <int> &ans){
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL){
            return;
        }
        
        if(root->right){
            rightBoundary(root->right, ans);
        }
        else{
            rightBoundary(root->left, ans);
        }
        ans.push_back(root->data);
    }
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector <int> ans;
    
        ans.push_back(root->data);
        
        leftBoundary(root->left, ans);
        
        leafBoundary(root->left, ans);
        leafBoundary(root->right, ans);
        
        rightBoundary(root->right, ans);
        
        return ans;
    }
};