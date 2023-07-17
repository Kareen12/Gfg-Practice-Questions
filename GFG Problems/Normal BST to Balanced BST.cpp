

/*Structure of the Node of the BST is as
struct Node
{
	int data;
	Node* left, *right;
};
*/
// Your are required to complete this function
// function should return root of the modified BST
void inorderOfBst(Node* root, vector<int> &inorder){
        if(!root) return;

        inorderOfBst(root->left, inorder);
        inorder.push_back(root->data);
        inorderOfBst(root->right, inorder);
    }

    Node* solve(vector<int> &inorder, int s, int e){
        if(s > e){
            return NULL;
        }

        int mid = s+ (e-s)/2;
        Node* root = new Node(inorder[mid]);

        root->left = solve(inorder, s, mid-1);
        root->right = solve(inorder, mid+1, e);

        return root; 
    }
Node* buildBalancedTree(Node* root)
{
	// Code here
	vector<int> inorder;
    inorderOfBst(root, inorder);

    int n = inorder.size();
    int s = 0;
    int e = n-1;
    return solve(inorder, s, n-1);
}