//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int v[], int n, int x) {
	    // code here
        int res1=-1;
        int start=0;
        int end=n-1;
        while(start<=end){
          int mid = start +(end-start)/2;
            if(v[mid]==x){
                res1=mid;
                end=mid-1;
            }
            else if(v[mid]>x)
             end=mid-1;
            else
             start=mid+1;
        }
        if(res1 != -1){
            int res2=-1;
            start=0;
            end=n-1;
            while(start<=end){
             int mid= start +(end-start)/2;
                if(v[mid]==x){
                    res2=mid;
                     start=mid+1;
                }
                else if(v[mid]>x)
                 end=mid-1;
                else
                 start=mid+1;
            }
            int ans = res2 - res1 + 1;
            return ans;
        }
        return 0;
	}
};