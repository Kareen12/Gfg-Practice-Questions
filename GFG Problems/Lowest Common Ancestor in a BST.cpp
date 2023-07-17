//Function to find the lowest common ancestor in a BST.
class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            // code here
            if(!root) return nullptr;

            if(n1 < root->data && n2 < root->data){
                return LCA(root->left, n1, n2);
            }
            else if(n1 > root->data && n2 > root->data){
                return LCA(root->right, n1, n2);
            }
            return root;
    
        }

};