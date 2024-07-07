// USING MEMOISATION    
class Solution
{
    int solve(int w, int wt[], int val[], int n,  vector<vector<int>>& dp) {
        if(n == 0){
           if(wt[0] <= w){
               return val[0];
           }
           else{
               return 0;
           }
        }
        
        if(dp[n][w] != -1){
            return dp[n][w];
        }
        int include = 0;
        if(w - wt[n] >= 0){
            include = solve(w-wt[n], wt, val, n-1, dp) + val[n];
        }
        int exclude = solve(w, wt, val, n-1, dp);
        
        dp[n][w] = max(include, exclude);
        return dp[n][w];
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n, vector<int>(W+1, -1));
       return solve(W, wt, val, n-1, dp);
    }
};

// USING TABULATION
class Solution
{
    int solveUsingTab(int w, int wt[], int val[], int n){
         vector<vector<int>> dp(n, vector<int>(w+1, 0));
         
         for(int i=wt[0]; i<=w; i++){
             if(wt[0] <= w){
                 dp[0][i] = val[0];
             }
             else{
                 dp[0][i] = 0;
             }
         }
         
         for(int i=1; i<n; i++){
             for(int j=0; j<=w; j++){
                 int include = 0;
                 if(j - wt[i] >= 0){
                    include = dp[i-1][j- wt[i]] + val[i];
                 }
                 int exclude = dp[i-1][j];
                 dp[i][j] = max(include, exclude);
             }
         }
         return dp[n-1][w];
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       return solveUsingTab(W, wt, val, n);
    }
};

// SPACE OPTIMISED SOLUTION
class Solution
{
    int solveUsingSpaceOpt(int w, int wt[], int val[], int n){
        vector<int> prev(w+1, 0);
        vector<int> curr(w+1, 0);
        
        for(int i=wt[0]; i<=w; i++){
             if(wt[0] <= w){
                 prev[i] = val[0];
             }
             else{
                 prev[i] = 0;
             }
         }
         
         for(int i=1; i<n; i++){
             for(int j=0; j<=w; j++){
                 int include = 0;
                 if(j - wt[i] >= 0){
                    include = prev[j-wt[i]] + val[i];
                 }
                 int exclude = prev[j];
                 curr[j] = max(include, exclude);
             }
             prev = curr;
         }
         return prev[w];
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       return solveUsingSpaceOpt(W, wt, val, n);
    }
};

// MORE SPACE OPTMISED SOLUTION
class Solution
{ 
    int solveUsingMoreSpaceOpt(int w, int wt[], int val[], int n){
        vector<int> prev(w+1, 0);
        
        for(int i=wt[0]; i<=w; i++){
             if(wt[0] <= w){
                 prev[i] = val[0];
             }
             else{
                 prev[i] = 0;
             }
         }
         
         for(int i=1; i<n; i++){
             for(int j=w; j>=0; j--){
                 int include = 0;
                 if(j - wt[i] >= 0){
                    include = prev[j-wt[i]] + val[i];
                 }
                 int exclude = prev[j];
                 prev[j] = max(include, exclude);
             }
         }
         return prev[w];
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       return solveUsingMoreSpaceOpt(W, wt, val, n);
    }
};