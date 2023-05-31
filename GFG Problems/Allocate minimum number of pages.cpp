//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int A[], int N, int M, int mid)
    {
        int stdCount = 1;
        int pgSum = 0;
        
        for(int i=0;i<N;i++)
        {
            if(A[i] > mid){
                return false;
            }
            if(pgSum + A[i] > mid){
                stdCount++;
                pgSum = A[i];
                if(stdCount > M) return false;
            }
            else{
                pgSum+=A[i];
            }
        }
        return true;
    }
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N) return -1;
        int s = 0;
        
        int sum = 0;
        
        for(int i=0;i<N;i++){
            sum+=A[i];
        }
        
        int e = sum;
        int mid = s+(e-s)/2;
        int ans = -1;
        
        while(s <= e){
            
            if(isPossible(A,N,M,mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
};