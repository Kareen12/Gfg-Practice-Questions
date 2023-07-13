//User function Template for C++
/*Structure of the node of the binary tree is as
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
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector <int> ans, ans_temp;
    	if(!root) return ans;
    	
    	queue<Node*> q;
    	q.push(root);
    	bool flag = true;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                Node* temp = q.front();
                q.pop();
                ans_temp.push_back(temp->data);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(!flag) reverse(ans_temp.begin(), ans_temp.end());
            flag = !flag;
            for(int i: ans_temp){
                ans.push_back(i);
            }
            ans_temp.clear();
        }
        return ans;
    	
    	
    }
};