//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        vector<int> output;
        int i = 0;
        int j = 1;
        // bool hasEntered = false;
        while(i<n && j<n){
            bool hasEntered = false;
            if(arr[i]>arr[j]){
                hasEntered = true;
                output.push_back(arr[j]);
                i++;
                j = i+1;
            }else{
                j++;
            }
            if(j==n && !hasEntered){
                output.push_back(-1);
                i++;
                j = i+1;
            }
        }
        output.push_back(-1);
        return output;
    } 
};

// ANOTHER APPROACH USING STACK

 //User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        vector<int> vec;
        stack<int>s;
        for(int i=n-1; i>=0; i--){
            if(!s.empty()){
                while(!s.empty() && s.top()>=arr[i]){
                    s.pop();
                }
            }
            if(s.empty()){
                vec.push_back(-1);
            }
            else{
                vec.push_back(s.top());
            }
            s.push(arr[i]);
        }
        reverse(vec.begin(), vec.end());
        return vec;
    } 
};

//BETTER ONE
class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
        vector<int> vec(n);
        stack<int>s;
        s.push(-1);
        for(int i=n-1; i>=0; i--){
            int curr = arr[i];
            
            while(!s.empty() && s.top()>=curr){
                    s.pop();
            }
            vec[i] = s.top();
            s.push(curr);
         }
        return vec;
    } 
};