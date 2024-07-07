// User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function

int ans;
bool solve(Node *root, int &k, int node)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == node)
    {
        return true;
    }

    bool left = solve(root->left, k, node);
    bool right = solve(root->right, k, node);

    if (left || right)
    {
        k--;
        if (k == 0)
        {
            ans = root->data;
        }
    }

    return left || right;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    ans = -1;
    solve(root, k, node);
    return ans;
}
Node *solve(Node *root, int &k, int node)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == node)
    {
        return root;
    }

    Node *leftAns = solve(root->left, k, node);
    Node *rightAns = solve(root->right, k, node);

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node *ans = solve(root, k, node);
    if (ans == NULL || ans->data == node)
    {
        return -1;
    }
    else
    {
        return ans->data;
    }
}