

/*
Structure of the binary Search Tree is as
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
// your task is to complete the Function
// Function should return median of the BST

//USING MORRIS TRAVERSAL TO COUNT THE NUMBER OF NODES IN THE TREE
int morrisTraversal(Node* root) {
        int ans = 0;
        
        // if(root == NULL){
        //     return ans;
        // }
        
        Node* curr = root;
        while(curr){
            if(curr->left == nullptr){
                ans++;
                // ans.push_back(curr->val);
                curr = curr->right;
            }
            //left is not null
            else{
                Node* pred = curr->left;
                while(pred->right != curr && pred->right){
                    pred = pred->right;
                }

                if(pred->right== nullptr){
                    pred->right = curr;
                    curr = curr->left;
                }
                else{
                    pred->right = nullptr;
                    ans++;
                    // ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
    
    //USING MORRIS TRAVERSAL TO FIND MEDIAN
   float solve(Node* root, int n) {
        int odd = (n+1)/2;
        int even1 = n/2; int even2 = n/2 + 1;
        int oddVal = -1, evenVal1 = -1, evenVal2 = -1;
        int i = 0;
        
        Node* curr = root;
        while(curr){
            if(curr->left == nullptr){
                i++;
                if(i == odd) oddVal = curr->data;
                if(i == even1) evenVal1 = curr->data;
                if(i == even2) evenVal2 = curr->data;
                curr = curr->right;
            }
            //left is not null
            else{
                Node* pred = curr->left;
                while(pred->right != curr && pred->right){
                    pred = pred->right;
                }

                if(pred->right== nullptr){
                    pred->right = curr;
                    curr = curr->left;
                }
                else{
                    pred->right = nullptr;
                    i++;
                    if(i == odd) oddVal = curr->data;
                    if(i == even1) evenVal1 = curr->data;
                    if(i == even2) evenVal2 = curr->data;
                    curr = curr->right;
                }
            }
        }
        float median = 0.0;
        if((n&1) == 0){
            median = (evenVal1 + evenVal2) / 2.0;
        }
        else{
            median = oddVal;
        }
        return median;
    }
float findMedian(struct Node *root)
{
      //Code here
      int n = morrisTraversal(root);
      return solve(root, n);
}