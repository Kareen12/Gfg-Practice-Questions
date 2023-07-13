/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
    bool isMirror(Node* p, Node* q) {
       if(!p && !q){
           return p == q;
       }
       if(p && q){
           return (p->data == q->data) && isMirror(p->left, q->right) && 
                                         isMirror(p->right, q->left);
       }
       return false;
    }
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    if(!root) return 1;
	    return isMirror(root->left, root->right);
    }
};