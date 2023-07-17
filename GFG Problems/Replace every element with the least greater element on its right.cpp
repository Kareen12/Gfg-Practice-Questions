//Back-end complete function Template for C++

class Node{
    public:
    int data;
    Node *left,*right;
    Node(int val): data(val), left(0), right(0){};
};

class Solution{
    Node* insert(Node* root, int i, int &succ){
        if(!root) return new Node(i);
        
        if(i >= root->data){
            root->right = insert(root->right, i, succ);
        }
        else{
            succ = root->data;
            root->left = insert(root->left, i, succ);
        }
        return root;
    }
    public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(n, -1);
        Node* root = 0;
        for(int i=n-1; i>=0; i--){
            int succ = -1;
            root = insert(root, arr[i], succ);
            ans[i] = succ;
        }
        return ans;
    }
};