class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int> ans;
        if(!root) return ans;
        // Map contains mpping from row->col->sare nodes. Sre nodes ko store karne ke liye multiset liya h kyoki wo similar values ko rakh leta h unlike set but sorted order me rakhta h jo hume cahiye according to the ques , just like set jo sorted order me values rakhta h
        map<int, map<int, vector<int>> > mp; 
        // queue contains node and pair of its corresponding row and col
        queue<pair<Node*, pair<int,int>> > q;
        q.push({root, {0,0}});

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            Node* node = temp.first; //yaha se node mili
            //yaha se row or col ki value mili in form of pair
            auto rowCol = temp.second; 
            int &row = rowCol.first;
            int &col = rowCol.second;

            //map me col or row ke corresponding node dal di
            mp[col][row].push_back(node->data);

            if(node->left){
                q.push({node->left, {row+1, col-1}});
            }
            if(node->right){
                q.push({node->right,{ row+1, col+1}});
            }
        }
        for(auto i: mp){
            for(auto j: i.second){
                for(auto k: j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};
