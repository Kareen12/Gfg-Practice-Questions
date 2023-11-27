//User function Template for C++

class info{
    public:
    int data;
    int row;
    int col;
    
    info(int val, int r, int c){
        this->data = val;
        this->row = r;
        this->col = c;
    }
};

class compare{
    public:
    bool operator()(info* a, info* b){
        return a->data > b->data;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> ans;
        int n = arr.size();
        priority_queue<info*, vector<info*>, compare> pq;
        
        for(int i=0; i<K; i++){
            info* temp = new info(arr[i][0], i, 0);
            pq.push(temp);
        }
        
        while(!pq.empty()){
            info* top = pq.top();
            pq.pop();
            
            ans.push_back(top->data);
            
            if(top->col + 1 <n){
                info* newPush = new info(arr[top->row][top->col + 1], top->row, top->col+1);
                pq.push(newPush);
            }
        }
        return ans;
    }
};