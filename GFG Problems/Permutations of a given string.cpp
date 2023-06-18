class Solution
{
	public:
    	void solve(string& s, vector<string>& ans, int i){
    	    if(i >= s.length()) {
    	        // ABB case me two times same strings aa rhi thi 
    	        for(int k=0; k<ans.size();k++){
    	            if(s == ans[k]) return;
    	        }
    	        
    	        ans.push_back(s);
    	        return;
    	    }

    	    for(int j = i;j<s.length();j++){
    	        swap(s[i],s[j]);
    	        
    	        solve(s, ans, i+1);
    	        
    	        swap(s[i],s[j]);
    	    }
    	}
    	
		vector<string>find_permutation(string& S)
		{
		    // Code here there
		    vector<string> ans;
		    int i = 0;
		    solve(S, ans, i);
		    sort(ans.begin(),ans.end());
		    return ans;
		    
		}
};
