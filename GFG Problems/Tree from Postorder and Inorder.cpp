/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node* solve(int postorder[], int inorder[], int &postInd, int inStartInd, int inEndInd, int size, unordered_map<int, int> &mp){
        if(postInd < 0 || inStartInd > inEndInd){
            return NULL;
        }

        int rootElement = postorder[postInd--];
        Node* root = new Node(rootElement);

        //finding rootElement in inorder vector
        int pos = mp[root->data];

        //isme pehle right ki call marni h
        root->right = solve(postorder, inorder, postInd, pos+1, inEndInd, size, mp);
        root->left =  solve(postorder, inorder, postInd, inStartInd, pos-1, size, mp);

        return root;
    }
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        mp[in[i]] = i;
    }
    int postInd = n-1, inStartInd = 0, inEndInd = n-1;
    return solve(post, in, postInd, inStartInd, inEndInd, n, mp);
}