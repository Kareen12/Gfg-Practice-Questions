class Solution{
    public:
    int search(int A[], int l, int h, int target){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        while(l<=h){
            int mid = l+(h-l)/2;
            
            if(A[mid]== target) {
                return mid;
            }
            else if(A[l]<=A[mid]){
                if(target>=A[l] && target<=A[mid]){
                    h=mid-1;
                }
                else {
                    l=mid+1;
                }
            }
            else{
               if(target>=A[mid] && target<=A[h]){
                    l=mid+1;
                }
                else {
                    h=mid-1;
                }
            }
        }
        return -1;
     
    }
};