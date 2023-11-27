    // ETHOD 1
class Solution{
    int M = 1000000007;
    long long solveUsingMemo(int n, int k, vector<int> &dp){
        //Base cases
        if(n == 1){
            return k;
        }
        if(n == 2){
            return k + k*(k-1);
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        dp[n] = ((solveUsingMemo(n-2, k, dp)%M + solveUsingMemo(n-1, k, dp)%M) * (k-1)) % M;
        return dp[n];
    }
    public:
    long long countWays(int n, int k){
        // code here
        vector<int> dp(n+1, -1);
        int ans = solveUsingMemo(n, k, dp);
        ans = ans % M;
        return ans;
    }
};

//METHOD 2  
class Solution{
    int M = 1000000007;  
    long long solveUsingTab(int n, int k){
         vector<long long> dp(n+1, 0);
         
         dp[1] = k;
         dp[2] =  k + k*(k-1);
         
         for(int i=3; i<=n; i++){
             dp[i] = ((dp[i-2] + dp[i-1] )* (k-1)) % M;
         }
         return dp[n];
    }
    public:
    long long countWays(int n, int k){
        // code here
        long long ans = solveUsingTab(n, k);
        ans = ans % M;
        return ans;
    }
};

// METHOD 3
class Solution{
    int M = 1000000007; 
    long long solveUsingSO(int n, int k){
        long long int prev2 = k;
        long long  prev1 =  (k + k*(k-1));
        for(int i=3; i<=n; i++){
            long long int first = prev2 % M;
            long long int second = prev1 % M;
            long long int sum = (first + second) % M;
            long long int curr = (sum*(k-1)) % M;
            
            prev2 = prev1;
            prev1 = curr;
        }
         return prev1;
    }
    public:
    long long countWays(int n, int k){
        // code here
        if(n==1) return k;
        long long ans = solveUsingSO(n, k);
        return ans;
    }
};

