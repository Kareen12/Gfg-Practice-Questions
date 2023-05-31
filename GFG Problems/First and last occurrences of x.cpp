vector<int> find(int arr[], int n , int x )
{
    // code here
    int s=0;
    int e=n-1;
    // int mid=s+(e-s)/2;
    int ans1=-1;
    vector<int> sol;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(x==arr[mid]){
            ans1=mid;
            e=mid-1;
        }
        if(x<arr[mid]){
            e=mid-1;
        }
        if(x>arr[mid]){
            s=mid+1;
        }
    }
    sol.push_back(ans1);
    
    int s2=0;
    int e2=n-1;
    int ans2=-1;
    // int mid2=s2+(e2-s2)/2;
     while(s2<=e2)
    {
        int mid2=s2+(e2-s2)/2;
        if(x==arr[mid2]){
            ans2=mid2;
            s2=mid2+1;
        }
        if(x<arr[mid2]){
            e2=mid2-1;
        }
        if(x>arr[mid2]){
            s2=mid2+1;        
        }
    }
    sol.push_back(ans2);
    
    return sol;
}