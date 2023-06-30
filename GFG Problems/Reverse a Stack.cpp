//User function Template for C++

class Solution{
public:
    void insertAtBottom(stack<int> &s, int target){
        if(s.empty()){
            s.push(target);
            return;
        }
        
        int temp = s.top();
        s.pop();
        
        insertAtBottom(s, target);
        s.push(temp);
    }
    
    void Reverse(stack<int> &s){
        if(s.empty()) return;
        
        int target = s.top();
        s.pop();
        
        Reverse(s);
        
        insertAtBottom(s, target);
    }
};