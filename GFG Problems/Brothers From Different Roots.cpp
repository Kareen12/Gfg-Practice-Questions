// APPROACH 1

//User function Template for C++

/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
    void inorder(Node* root, vector<int> &in1){
        if(!root) return;
        
        inorder(root->left, in1);
        in1.push_back(root->data);
        inorder(root->right, in1);
    }
    
    void reverseInorder(Node* root, vector<int> &in2){
        if(!root) return;
        
        reverseInorder(root->right, in2);
        in2.push_back(root->data);
        reverseInorder(root->left, in2);
    }
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        vector<int> in1;
        inorder(root1, in1);
        vector<int> in2;
        reverseInorder(root2, in2);
        
        int i = 0, j = 0;
        int count = 0;
        while(i < in1.size() && j < in2.size()){
            int sum = in1[i] + in2[j];
            if(sum < x){
                i++;
            }
            else if(sum > x){
                j++;
            }
            else{
                count++;
                i++;
                j++;
            }
        }
        return count;
    }
};

// APPROACH 2

/User function Template for C++

/*Structure of the Node of the BST is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        int count = 0;
        stack<Node*> s1, s2;
        Node* a = root1;
        Node* b = root2;
        
        while(1)
        {
            //inorder
            while(a){
                s1.push(a);
                a = a->left;
            }
            //reverse inorder
            while(b){
                s2.push(b);
                b = b->right;
            }
            
            if(s1.empty() || s2.empty()){
                break;
            }
            
            auto atop = s1.top();
            auto btop = s2.top();
            
            int sum = atop->data + btop->data;
            
            if(sum == x){
                count++;
                s1.pop();
                s2.pop();
                a = atop->right;
                b = btop->left;
            }
            else if(sum < x){
                s1.pop();
                // aage ka inorder traversal
                a = atop->right;
            }
            else{
                s2.pop();
                 // aage ka reverse inorder traversal
                b = btop->left;
            }
        }
        return count;
    }
};