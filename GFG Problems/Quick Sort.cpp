class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low >= high) return;
        
        int pivot_pos = partition(arr, low, high);
        
        quickSort(arr, low, pivot_pos-1);
        quickSort(arr, pivot_pos+1, high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pivotIndex = low;
       int pivot = arr[low];
       int count = 0;
       for(int k=low+1;k<=high;k++){
           if(arr[k] <= pivot){
               count++;
           }
       }
       swap(arr[pivotIndex], arr[low+count]);
       pivotIndex = low + count;
      
       int i = low;
       int j = high;
       
       while(i<pivotIndex && j>pivotIndex){
           while(arr[i] <= pivot) {i++;}
           while(arr[j] > pivot) {j--;}
           
           if(i<pivotIndex && j>pivotIndex){
                swap(arr[i++], arr[j--]);
           }
       }
       return pivotIndex;
      
    }
};