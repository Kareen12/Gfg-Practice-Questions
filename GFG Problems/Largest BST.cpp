/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    bool checkBST(Node *root, int lb, int ub){
        if(!root) return 1;
        
        if((root->data > lb && root->data < ub) && checkBST(root->right, root->data, ub) 
        && checkBST(root->left, lb, root->data)){
            return 1;
        }
        else{
            return 0;
        }
    }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	if(!root) return 0;
    	
    	if(checkBST(root, INT_MIN, INT_MAX)){
    	    return largestBst(root->left) + largestBst(root->right) + 1;
    	}
    	else{
    	    return max(largestBst(root->left), largestBst(root->right));
    	}
    }
};

//ANOTHER APPROACH

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    class info{
        public:
        int maxi;
        int mini;
        bool isBST;
        int size;
    };
    
    info solve(Node* root, int &ans){
        if(root==NULL){
            return {INT_MIN , INT_MAX, true,0};
        }
        
        info left = solve(root->left,ans);
        info right = solve(root->right,ans);
        
        info currNode;
        currNode.size = left.size+right.size+1;
        currNode.maxi = max(root->data,right.maxi);
        currNode.mini = min(root->data, left.mini);
        
        if(left.isBST && right.isBST && (root->data > left.maxi && root->data <right.mini) ){
            currNode.isBST= true;
        }
        else{
            currNode.isBST = false;
        }
        
        //ans update
        if(currNode.isBST){
            ans = max(ans,currNode.size);
        }
        return currNode;
    }
    int largestBst(Node *root)
    {
        int maxsize=0;
        info temp = solve(root,maxsize);
        return maxsize;
    }
};