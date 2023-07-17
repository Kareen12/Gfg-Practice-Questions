/*Complete the function below
Node is as follows
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
    void inorder(Node* root, vector<int> &inorderOfBst){
        if(!root) return;

        inorder(root->left, inorderOfBst);
        inorderOfBst.push_back(root->data);
        inorder(root->right, inorderOfBst);
    }
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
        //add code here.
        vector<int> inorderOfBst;
        inorder(root, inorderOfBst);

        int s = 0;
        int e = inorderOfBst.size()-1;

        while(s<e){
            int sum = inorderOfBst[s] + inorderOfBst[e];

            if(sum == target){
                return 1;
            }
            else if(sum > target){
                e--;
            }
            else{
                s++;
            }
        }
        return 0;
    }
};