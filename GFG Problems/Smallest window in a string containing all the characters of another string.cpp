class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        if(s.length() < p.length()){
            return "-1";
        }
        vector<int> mp(26, 0);
        int count = 0;
        for(int i=0; i<p.length(); i++){
            if(mp[p[i]-'a'] == 0){
                count++;
            }
            mp[p[i]-'a']++;
        }
        
        int i = 0, j = 0;
        int len = INT_MAX;
        int start = 0;
        while(j < s.size()){
            mp[s[j]-'a']--;
            if(mp[s[j]-'a'] == 0){
                count--;
            }
            
            if(count == 0){
                while(count == 0){
                    mp[s[i]-'a']++;
                    if(mp[s[i]-'a'] == 1){
                        count++;
                    }
                    if(len > j-i+1){
                        len = j-i+1;
                        start = i;
                    }
                    i++;
                }
            }
            j++;
        }
        if(len == INT_MAX){
            return "-1";
        }
        return s.substr(start, len);
    }
};