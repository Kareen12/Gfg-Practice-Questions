
class Solution{
    public:
    string convert(string s, int n) {
        //code
        if(n==1) return s;
        
        int i = 0;
        int row = 0;
        bool direction = 1;
        vector<string> zigzag(n);
        while(true){
            if(direction){
                while(i<s.length() && row<n){
                    zigzag[row++].push_back(s[i++]);
                }
                row = n-2;
            }
            else{
                while(i<s.length() && row>=0){
                    zigzag[row--].push_back(s[i++]);
                }
                row = 1;
            }
            
            if(i>=s.size()) break;
            direction = !direction;
        }
        string ans = "";
        for(int i=0;i<zigzag.size();i++){
            ans+=zigzag[i];
        }
        return ans;
    }
};