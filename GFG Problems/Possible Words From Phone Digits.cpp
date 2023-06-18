//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void solve(int a[], int n, vector<string> &ans, string mp[], string output, int index){
        if(index >= n){
            ans.push_back(output);
            return;
        }
        int digit = a[index];
        string value = mp[digit];
        
        for(int i=0; i<value.length(); i++){
            char ch = value[i];
            output.push_back(ch);
            solve(a, n, ans, mp, output, index+1);
            //Backtracking
            output.pop_back();
        }
    }
    
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> ans;
        string mp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string output = "";
        solve(a, N, ans, mp, output, 0);
        return ans;
    }
};