class Solution{
    int solve(int n, vector<int> &dp){
        if(n == 1 || n == 2){
            return n;
        }

        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = solve(n-2, dp) + 1;
        return dp[n];
    }
	public:
		int nthStair(int n){
		    //  Code here
		    vector<int> dp(n+1, -1);
            return solve(n, dp);
		}
};