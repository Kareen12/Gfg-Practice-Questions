class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans;
		    queue<char> q;
		    int freq[26] = {};
		    
		    for(int i=0; i<A.size(); i++){
		        char ch = A[i];
		        
		        freq[ch - 'a']++;
		        
		        q.push(ch);
		        
		        while(!q.empty()){
		            if(freq[q.front() - 'a'] > 1){
		                q.pop();
		            }
		            else{
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        
		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};