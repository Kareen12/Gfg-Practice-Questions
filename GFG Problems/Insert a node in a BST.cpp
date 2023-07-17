// Function to insert a node in a BST.
Node* insert(Node* root, int key) {
    // Your code here
    if(!root) return new Node(key);
    // Node* temp = root;
    // if(temp->data == key){
    //     return temp;
    // }
    else if(root->data > key){
        root->left = insert(root->left, key);
    }
    else if(root->data < key){
        root->right = insert(root->right, key);
    }
    return root;
}

//ANOTHER APPROACH(Iterative)



// Function to insert a node in a BST.
Node* insert(Node* root, int key) {
    // Your code here
    Node* temp = root;
    // Node* newNode = new Node(key);
    while(temp){
        //Node* newNode = new Node(key);
        if(temp->data == key) return root;
        if(temp->data > key){
            if(!temp->left){
                temp->left = new Node(key);;
                break;
            }
            else{
                temp = temp->left;
            }
        }
        else if(temp->data < key){
            if(!temp->right){
                temp->right = new Node(key);;
                break;
            }
            else{
                temp = temp->right;
            }
        }
    }
    return root;
}
