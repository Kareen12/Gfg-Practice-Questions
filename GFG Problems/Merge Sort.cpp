class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int n1 = m-l+1;
         int n2 = r-m;
         
         int *a = new int[n1];
         int *b = new int[n2];
         
         int k=l;
         for(int i=0;i<n1;i++)
         {
             a[i]=arr[k++];
         }
         k=m+1;
         for(int i=0;i<n2;i++)
         {
             b[i]=arr[k++];
         }
         int i=0,j=0;
         k=l;
         while(i<n1 && j<n2)
         {
             if(a[i]<b[j]){
                 arr[k++]=a[i++];
             }
             else{
                 arr[k++]=b[j++];
             }
         }
         while(i<n1){
             arr[k++]=a[i++];
             
         }
         while(j<n2){
             arr[k++]=b[j++];
 
         }
         delete []a;
         delete []b;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r){
            return;
        }
        int m = l+(r-l)/2;
        
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        
        merge(arr,l,m,r);
        
    }
};