class Solution {
  public:
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int low= *max_element(arr,arr+N);
        int high= accumulate(arr,arr+N,0);
        int ans=low;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int x=no_of_subarray(arr,N,mid);
            if(x>K){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
             }
        }
         return ans;
    }
    
    
    int no_of_subarray(int arr[],int N,int mid)
    {
        int sum=0;
        int count=1;

        for(int i=0;i<N;i++)
        {
            if(sum+arr[i]>mid){
                sum=arr[i];
                count++;
            }
            else{
                sum+=arr[i];
            }
        }
        return count;

    }
};