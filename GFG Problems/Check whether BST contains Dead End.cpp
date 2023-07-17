

/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
void solve(Node* root, unordered_map<int, bool> &mp, bool &ans){
    if(!root) return;
    
    mp[root->data] = 1;
    
    if(!root->left && !root->right){
        int dataPlus1 = root->data + 1;
        int dataMinus1 = root->data - 1 == 0 ? root->data : root->data - 1;;
        if(mp.find(dataPlus1) != mp.end() && mp.find(dataMinus1) != mp.end()){
            ans = true;
        return;
        }
    }
    solve(root->left, mp, ans);
    solve(root->right, mp, ans);
}
bool isDeadEnd(Node *root)
{
    //Your code here
    bool ans = false;
    unordered_map<int, bool> mp;
    solve(root, mp, ans);
    return ans;
}