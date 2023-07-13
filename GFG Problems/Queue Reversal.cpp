//function Template for C++

//Function to reverse the queue.
class Solution
{
    public:
    void revrec(queue<int> &q){
        if(q.empty()) return;
        
        int fr = q.front();
        q.pop();
        revrec(q);
        q.push(fr);
    }
    
    queue<int> rev(queue<int> q)
    {
        // add code here.
        revrec(q);
        return q;
    }
};