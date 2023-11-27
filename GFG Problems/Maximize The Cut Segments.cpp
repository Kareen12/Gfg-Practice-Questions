class Solution
{
    int solve(int n, int x, int y, int z,  vector<int> &dp){
        if(n == 0){
            return 0;
        }
        if(n < 0){
            return INT_MIN;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        // int maxx = INT_MIN;
        int ax = solve(n-x, x, y, z, dp) + 1;
        int wy = solve(n-y, x, y, z, dp) + 1;
        int zd = solve(n-z, x, y, z, dp) + 1;
        
        dp[n] = max(ax, max(wy, zd));
        // dp[n] = maxx;
        return dp[n];
    }
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
       vector<int> dp(n+1, -1);
       int ans = solve(n, x, y, z, dp); 
       if(ans < 0) return 0;
       else
          return ans;
    }
};