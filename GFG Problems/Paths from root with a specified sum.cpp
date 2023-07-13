//User function Template for C++

/*// A Tree node
struct Node
{
	int key;
	struct Node *left, *right;
};*/

class Solution
{
    void solve(Node* root, int targetSum, int sum, vector<vector<int>> &ans,
        vector<int> path ){
            if(root == NULL){
                return;
            }
            
            path.push_back(root->key);
            sum += root->key;
            
            if(sum == targetSum){
                ans.push_back(path);
            }
            // path.pop_back();
            // sum -= root->key;
            // return;


            solve(root->left, targetSum, sum, ans, path);
            solve(root->right, targetSum, sum, ans, path);

            //bactracking bcoz by refrence pass kiya h
            // path.pop_back();
            // sum -= root->key;
        }
    public:
    vector<vector<int>> printPaths(Node *root, int targetSum)
    {
        //code here
        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;
        solve(root, targetSum, sum, ans, path);
        return ans;
    }
};

//When passed by reference(saves time and memory)

//User function Template for C++

/*// A Tree node
struct Node
{
	int key;
	struct Node *left, *right;
};*/

class Solution
{
    void solve(Node* root, int targetSum, int sum, vector<vector<int>> &ans,
        vector<int> &path ){
            if(root == NULL){
                return;
            }
            
            path.push_back(root->key);
            sum += root->key;
            
            if(sum == targetSum){
                ans.push_back(path);
                path.pop_back();
                sum -= root->key;
                return;
            }


            solve(root->left, targetSum, sum, ans, path);
            solve(root->right, targetSum, sum, ans, path);

            //bactracking bcoz by refrence pass kiya h
            path.pop_back();
            sum -= root->key;
        }
    public:
    vector<vector<int>> printPaths(Node *root, int targetSum)
    {
        //code here
        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;
        solve(root, targetSum, sum, ans, path);
        return ans;
    }
};