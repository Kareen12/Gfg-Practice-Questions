// User function Template for C++

class Solution{
public:
    void add(vector<vector<int>> &board, vector<vector<int>> &ans, int n){
        vector<int> temp;
        // i -> col
        // j -> row
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[j][i] == 1){
                    temp.push_back(j+1);
                }
            }
        }
        ans.push_back(temp);
    }
    bool isSafe(vector<vector<int>> &board, int row, int col, int n){
        int i = row;
        int j = col;
        
        // checking row
        while(j>=0){
            if(board[i][j]==1){
                return false;
            }
            j--;
        }
        
        // checking upper diagonal
        i = row;
        j = col;
        while(i>=0 && j>=0){
            if(board[i][j]==1){
                return false;
            }
            i--;
            j--;
        }
        
        // checking lower diagonal
        i = row;
        j = col;
        while(i<n && j>=0){
            if(board[i][j]==1){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    void solve(vector<vector<int>> &board, vector<vector<int>> &ans, int n, int col){
        //Base Case
        if(col >= n){
            add(board, ans, n);
            return;
        }
        
        for(int row=0; row<n; row++){
            if(isSafe(board, row, col, n)){
                board[row][col] = 1;
                solve(board, ans, n, col+1);
                //Backtracking
                board[row][col] = 0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
         vector<vector<int>> board(n, vector<int>(n,0));
         vector<vector<int>> ans;
         solve(board, ans, n, 0);
         return ans;
         
    }
};