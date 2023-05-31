class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 

        int count=0;
        int total=r*c;

        int start=0;
        int end=c-1;
        int top=0;
        int bottom=r-1;

        vector<int> ans;

        while(count < total)
        {
            //first_row
            for(int row1=top;count<total && row1<=end;row1++)
            {
                ans.push_back(matrix[start][row1]);
                count++;
            }
            start++;
            //last_column
            for(int colLast=start;count<total && colLast<=bottom;colLast++)
            {
                ans.push_back(matrix[colLast][end]);
                count++;
            }
            end--;
            //last_row
            for(int rowLast=end;count<total && rowLast>=top;rowLast--)
            {
                ans.push_back(matrix[bottom][rowLast]);
                count++;
            }
            bottom--;
            //first_column
            for(int col1=bottom;count<total && col1>=start;col1--)
            {
                ans.push_back(matrix[col1][top]);
                count++;
            }
            top++;
        }
        return ans;
    }
};
        