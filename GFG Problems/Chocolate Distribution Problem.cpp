class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        sort(a.begin(),a.end());
        long minn=INT_MAX;
        long diff;
        for(int i=0;i+m-1<n;i++)
        {
            diff = a[i+m-1]-a[i];
            minn = min(diff,minn);
        }
        return minn;
    }   
};