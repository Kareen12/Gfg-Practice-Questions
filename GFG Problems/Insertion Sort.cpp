class Solution
{
    public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        for(int round=1; round<n; round++){
            int val=arr[round];
            int j=round-1;
            for(j=round-1;j>=0 && val<arr[j];j--){
              arr[j+1]=arr[j];
          }
            arr[j+1]=val;
        }
    }
};