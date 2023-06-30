//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& m, int n) 
    {
        // code here 
        stack<int> st;
        for(int i=0; i<n; i++){
            st.push(i);
        }
        
        while(st.size() != 1){
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            
            if(m[a][b]){
                //a knows b
                st.push(b);
            }
            else{
                //b knows a
                st.push(a);
            }
        }
        
        int isCeleb = st.top();
        
        //checking if everyone knows this celebrity or not
        
        //checking if this is actually celebrity or not
        //celebrity ka row pura 0 hona chahiye
        for(int col=0; col<n; col++){
            if(m[isCeleb][col] != 0) return -1;
        }
        
        //celebrity ko sab janne chahiye
        for(int row=0; row<n; row++){
            //agar column me kahi ) aa jata ya celebrity ke diagonal me 1 aa jata to wo celebrity 
            //ni h
            if(m[row][isCeleb] == 0 && row != isCeleb){
                return -1;
            }
        }
        return isCeleb;
        
    }
};