//User function template for C++
class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        int number=(size/2)+1;
        unordered_map<int,int> mp;
        for(int i=0;i<size;i++)
        {
            mp[a[i]]++;
        }
        for(auto items:mp){
            if(items.second>=number){
              return items.first;
              break;
            }
        }
        return -1;
    }
};