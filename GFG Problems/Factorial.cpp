class Solution{
public:
    long long int factorial(int N){
        //code here
        if(N==0) return 1;
        long long int ans = 1;
        for(int i=1; i<=N; i++){
            ans = ans*i;
        }
        return ans;
    }
};