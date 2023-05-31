class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        if(nums.size()%2==1){
            return false;
        }
        
        unordered_map<int,int> mp;
	    for(int i=0;i<nums.size();i++)
	    {
	        mp[nums[i]%k]++;
	    }
	    for(int i=0;i<nums.size();i++)
	    {
	        int rem=nums[i]%k;
	        
	        if(rem==0){
	            if(mp[rem]%2==1)
	            return false;
	        }
	        else if(mp[rem]!=mp[k-rem]){
	            return false;
	        }
	    }
        return true;
    }
};