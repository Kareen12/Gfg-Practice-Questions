class Solution
{
    public:
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        long long int n=v.size();
        long long int res1=-1;
        long long int start=0;
        long long int end=n-1;
        while(start<=end){
          long long int mid= start +(end-start)/2;
            if(v[mid]==x){
                res1=mid;
                end=mid-1;
            }
            else if(v[mid]>x)
             end=mid-1;
            else
             start=mid+1;
        }
        long long int res2=-1;
        start=0;
        end=n-1;
        while(start<=end){
         long long int  mid= start +(end-start)/2;
            if(v[mid]==x){
                res2=mid;
                 start=mid+1;
            }
            else if(v[mid]>x)
             end=mid-1;
            else
             start=mid+1;
        }
        pair<long,long> p(res1,res2);
        return p;
        
    }
};