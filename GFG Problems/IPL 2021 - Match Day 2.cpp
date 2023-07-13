class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> ans;
        deque<int> dq;
        
        for(int i=0; i<k; i++){
            while(!dq.empty() && arr[i]>=arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
         ans.push_back(arr[dq.front()]);
        
        for(int i=k; i<n; i++){
            if(!dq.empty() && i-dq.front() >= k){
                 dq.pop_front();
            }
            
            while(!dq.empty() && arr[i]>=arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            
            ans.push_back(arr[dq.front()]);
        }
        
        return ans;
    }
};