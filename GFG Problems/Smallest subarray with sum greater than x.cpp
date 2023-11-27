class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int s = 0, e = 0;
        int sum = 0;
        int len = INT_MAX;
        while(e < n){
            sum += arr[e];

            while(sum > x){
                int l = e-s+1;
                len = min(len, l);
                sum = sum - arr[s];
                s++;
            }
            e++;
        }
        if(len == INT_MAX){
            return 0;
        }else{
            return len;
        }
    }
};