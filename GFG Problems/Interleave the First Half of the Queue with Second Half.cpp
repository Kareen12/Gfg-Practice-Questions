//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        vector<int>ans;
        queue<int>q1;
        // int half = q.size()/2 - 1;
        int half = q.size()/2;
        
        int i = 0;
        while(i<half){
            int temp = q.front();
            q.pop();
            q1.push(temp);
            i++;
        }
        while(!q.empty() && !q1.empty()){
            int temp1 = q1.front();
            q1.pop();
            ans.push_back(temp1);
            
            int temp2 = q.front();
            q.pop();
            ans.push_back(temp2);
        }
        return ans;
    }
};