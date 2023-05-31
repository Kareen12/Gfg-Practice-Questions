// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        int ans=arr[n-1]-arr[0];
        int a=arr[0]+k;
        int b=arr[n-1]-k;
        int minn,maxx;
        
        for(int i=0;i<n;i++)
        {
            minn=min(a,arr[i+1]-k);
            maxx=max(b,arr[i]+k);
            if(minn<0) continue;
            ans=min(ans,maxx-minn);
        }
        return ans;
    }
};