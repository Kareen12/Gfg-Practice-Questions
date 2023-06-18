//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(vector<string> &ans, int n, int open, int close, string output){
        //Base case
        if(open == 0 && close == 0){
            ans.push_back(output);
            return;
        }
        
        if(open>0){
            output.push_back('(');
            solve(ans, n, open-1, close, output);
            //Backtracking
            output.pop_back();
        }
        
        if(close > open){
            output.push_back(')');
            solve(ans, n, open, close-1, output);
            //Backtracking
            output.pop_back();
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> ans;
        int open = n;
        int close = n;
        string output = "";
        solve(ans, n, open, close, output);
        return ans;
    }
};