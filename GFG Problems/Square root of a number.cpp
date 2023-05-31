// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here 
        long long int l=1;
        long long int h=x;
        int ans = 0;
        while (l<=h){
            long long int mid= l+(h-l)/2;
            
            if(mid*mid == x){
                return mid;
            }
            else if(mid*mid > x){
                h = mid-1;
            }
            else {
                ans = mid;
                l = mid+1;
            }
        }
        return ans;

    }
};