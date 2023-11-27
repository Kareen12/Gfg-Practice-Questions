class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    int n = s.length();
		    for(int i=0; i<(1<<n); i++){
		        string temp = "";
		        for(int j=0; j<n; j++){
		            if(i & (1<<j)){
		                temp += s[j];
		            }
		        }
		        if(temp.length() > 0){
		            ans.push_back(temp);
		        }
		    }
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

