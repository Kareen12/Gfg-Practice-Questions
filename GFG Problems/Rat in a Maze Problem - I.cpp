// SOLUTION 1

class Solution{
    private:
    bool isSafe(vector<vector<int>> &m,int n,int x,int y,vector<vector<int>> visited){
        if((x>=0 && x<n) && (y>=0 && y<n) && m[x][y]==1 && visited[x][y]==0 ){
            return true;
        }
        else{
            return false;
        }
    }
    void solve(vector<vector<int>> &m,int n,int x,int y, vector<vector<int>> visited,
              string path,vector<string>& ans){
                     if(x==n-1 && y==n-1){
                         ans.push_back(path);
                         return;
                     }
                     visited[x][y] = 1;
                     
                     //down
                     int newx = x+1;
                     int newy = y;
                     if(isSafe(m,n,newx,newy,visited)){
                         path.push_back('D');
                         solve(m,n,newx,newy,visited,path,ans);
                         path.pop_back();
                    }
                    //up
                     newx = x-1;
                     newy = y;
                     if(isSafe(m,n,newx,newy,visited)){
                         path.push_back('U');
                         solve(m,n,newx,newy,visited,path,ans);
                         path.pop_back();
                     }
                     //right
                     newx = x;
                     newy = y+1;
                     if(isSafe(m,n,newx,newy,visited)){
                         path.push_back('R');
                         solve(m,n,newx,newy,visited,path,ans);
                         path.pop_back();
                     }
                     //left
                     newx = x;
                     newy = y-1;
                     if(isSafe(m,n,newx,newy,visited)){
                         path.push_back('L');
                         solve(m,n,newx,newy,visited,path,ans);
                         path.pop_back();
                     }
                     
                     visited[x][y]=0;
                 }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;

        if(m[0][0]==0){
            return ans;
        }
        vector<vector<int>> visited=m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        string path = "";
        int srcx = 0;
        int srcy = 0;
        solve(m,n,srcx,srcy,visited,path,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// SOLUTION 2

class Solution{
    private:
    bool isSafe(vector<vector<int>> &m,int n,int x,int y,vector<vector<int>> &visited){
        if((x>=0 && x<n) && (y>=0 && y<n) && m[x][y]==1 && visited[x][y]==0 ){
            return true;
        }
        else{
            return false;
        }
    }
    void solve(vector<vector<int>> &m,int n,int x,int y, vector<vector<int>> &visited,
              string path,vector<string>& ans){
                     if(x==n-1 && y==n-1){
                         ans.push_back(path);
                         return;
                     }
                     
                     //down
                    //  int newx = x+1;
                    //  int newy = y;
                     if(isSafe(m,n,x+1,y,visited)){
                         visited[x+1][y] = 1;
                         solve(m,n,x+1,y,visited,path+'D',ans);
                         visited[x+1][y]=0;

                    }
                    //up
                    //  newx = x-1;
                    //  newy = y;
                     if(isSafe(m,n,x-1,y,visited)){
                         visited[x-1][y] = 1;
                         solve(m,n,x-1,y,visited,path+'U',ans);
                         visited[x-1][y]=0;
                     }
                     //right
                    //  newx = x;
                    //  newy = y+1;
                     if(isSafe(m,n,x,y+1,visited)){
                         visited[x][y+1] = 1;
                         solve(m,n,x,y+1,visited,path+'R',ans);
                         visited[x][y+1]=0;
                     }
                     //left
                    //  newx = x;
                    //  newy = y-1;
                     if(isSafe(m,n,x,y-1,visited)){
                         visited[x][y-1] = 1;
                         solve(m,n,x,y-1,visited,path+'L',ans);
                         visited[x][y-1]=0;
                     }
                     
    }
                 
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;

        if(m[0][0]==0){
            return ans;
        }
        // vector<vector<int>> visited(n, vector<int>(n,0));
        vector<vector<int>> visited=m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j]=0;
            }
        }
        visited[0][0] = 1;
        string path = "";
        int srcx = 0;
        int srcy = 0;
        solve(m,n,srcx,srcy,visited,path,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    