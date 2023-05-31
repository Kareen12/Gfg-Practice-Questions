//User function Template for C++
class Solution
{
    public:
    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        // Your code here  
        bool swapped = false;
        for (int round=1; round<n; round++){
            for(int j=0;j<n-round;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    swapped=true;
                }
            }
            if(swapped==false){
                break;
            }
            
        }
    }
};