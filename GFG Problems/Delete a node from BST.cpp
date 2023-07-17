// Function to delete a node from BST.
int maxVal(Node* root) {
    if(!root) return -1;
    
    while(true){
        if(root->right == NULL){
            return root->data;
            // break;
        }
        else{
            root = root->right;
        }
    }
}

Node *deleteNode(Node *root, int X) {
    // your code goes here
     if(!root) return NULL;

        if(root->data == X){
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            else if(root->left && !root->right){
                Node* child = root->left;
                delete root;
                return child;
            }
            else if(!root->left && root->right){
                Node* child = root->right;
                delete root;
                return child;
            }
            else{
                int inorderPred = maxVal(root->left);
                root->data = inorderPred;
                root->left = deleteNode(root->left, inorderPred);
                return root;
            }
        }
        else if(X < root->data){
            root->left =  deleteNode(root->left, X);
        }
        else if(X > root->data){
            root->right =  deleteNode(root->right, X);
        }
        return root;
    
}