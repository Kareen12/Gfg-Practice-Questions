// User function Template for C++

class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> ans;
        priority_queue<int> pq(a.begin(), a.end());
        for(int i=0; i<m; i++){
            pq.push(b[i]);
        }
        
        while(pq.size()>0){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};