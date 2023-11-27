class Solution
{
    int solveMini(int candies[], int n, int k){
        int i = 0;
        int j = n-1;
        
        int sum = 0;
        while(i<=j){
            sum += candies[i];
            i++;
            j-=k;
        }
        return sum;
    }
    
    int solveMaxi(int candies[], int n, int k){
        int i = n-1;
        int j = 0;
        
        int sum = 0;
        while(j<=i){
            sum += candies[i];
            i--;
            j+=k;
        }
        return sum;
    }
    
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies, candies+N);
        vector<int> ans;
        int mini = solveMini(candies, N, K);
        ans.push_back(mini);
        int maxi = solveMaxi(candies, N, K);
        ans.push_back(maxi);
        
        return ans;
    }
};