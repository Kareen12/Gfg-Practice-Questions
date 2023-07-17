/*The structure of Node

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
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        //Your code here
        Node* succ = 0;
        Node* curr = root;
        while(curr){
            if(x->data < curr->data){
                succ = curr;
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
        return succ;
    }
};