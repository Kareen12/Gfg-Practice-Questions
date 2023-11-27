//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    int curr = 0;
	    int prev2 = 0;
	    int prev1 = arr[0];
	    
	    for(int i=1; i<n; i++){
	        int temp = 0;
	        if(i-2 >= 0){
	            temp = prev2;
	        }
	        
	        int include = temp + arr[i];
	        int exclude = prev1;
	        curr = max(include, exclude);
	        prev2 = prev1;
	        prev1 = curr;
	    }
	    return prev1;
	}
};