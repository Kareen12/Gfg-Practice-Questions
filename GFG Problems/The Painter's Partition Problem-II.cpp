//User function template for C++

class Solution
{
  public:
  
    bool isPossible(int arr[], int n, int k, long long mid)
    {
        int count =1;
        long long summ = 0;
    
    for(int i=0;i<n;i++)   
    {
        if(arr[i] > mid){
            return false;
        }
        if(summ + arr[i] > mid){
            count++;
            summ = arr[i];
            if(count>k) return false;
        }
        else{
            summ+=arr[i];
        }
    }
    return true;
}
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        
        long long s = 0;
        long long e = 0;
        for(int i=0;i<n;i++){
            e+=arr[i];
        }
        
        long long ans = -1;
        
        while(s <= e)
        {
            long long mid = s+(e-s)/2;
            if(isPossible(arr,n,k,mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};