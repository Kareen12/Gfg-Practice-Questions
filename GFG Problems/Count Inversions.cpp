class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long merge(long long arr[],  long long temp[], int mid, int s, int e){
        int start = s;
        int end = mid +1;
        int k = s;
        long c = 0;
        while(start<=mid && end<=e){
            if(arr[start]<=arr[end]){
                temp[k++] = arr[start++];
            }
            else{
                temp[k++] = arr[end++];
                c += mid - start + 1;
            }
        }
        
        while(start <= mid){
            temp[k++] = arr[start++];
        }
        while(end <= e ){
            temp[k++] = arr[end++];
        }
        
        while(s <= e){
            arr[s] = temp[s];
            s++;
        }
        return c;
    }
    
    long mergeSort(long long arr[], long long temp[], int s, int e){
        if(s>=e) return 0;
        
        long c = 0;
        
        int mid = s + (e-s)/2;
        
        c += mergeSort(arr, temp, s, mid);
        
        c += mergeSort(arr, temp, mid+1, e);
        
        c += merge(arr, temp, mid, s, e);
        
        return c;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long temp[N];
        int c = 0;
        c = mergeSort(arr, temp, 0, N-1);
    }

};