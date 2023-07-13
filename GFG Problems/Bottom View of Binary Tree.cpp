//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        // creating mapping for horizontalDist -> node->data
        map<int, int> mp;
        //queue contains pair of nodeand its horizontlDist
        queue<pair<Node*, int> > q;
        
        q.push(make_pair(root, 0));
       
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int horizontalDist = temp.second;
            
            mp[horizontalDist] = frontNode->data;
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left, horizontalDist-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, horizontalDist+1));
            }
        }
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
    
};