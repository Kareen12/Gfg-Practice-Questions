// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
    bool isCompleteTree(Node* root) {
        queue<Node*> q;
        q.push(root);

        int foundNull = 0;
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            // agar koi null node mil jati h to uske baad koi non null node ni milno chahiye for it to be a complete binary tree 
            if(foundNull && temp!=NULL){
                return false;
            }
            if(temp == NULL){
                foundNull = 1;
                continue;
            }
            q.push(temp->left);
            q.push(temp->right);
        }
        return true;
    }
    
    pair<bool, int> solve(Node* tree){
        if(!tree){
            return {true, INT_MIN};
        }
        if(!tree->left && !tree->right){
            return {true, tree->data};
        }
        auto leftAns = solve(tree->left);
        auto rightAns = solve(tree->right);
        
        if(leftAns.first && rightAns.first && tree->data > leftAns.second && tree->data > rightAns.second){
            return {true, tree->data};
        }
        else{
            return {false, tree->data};
        }
    }
  public:
    bool isHeap(struct Node* tree) {
        // code here
        bool heapPropt1 =  solve(tree).first;
        bool completeness = isCompleteTree(tree);
        return heapPropt1 && completeness;
    }
};