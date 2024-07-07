/* Structure for tree and linked list

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// This function should return head to the DLL
class Solution
{
public:
    void solve(Node *root, Node *&head)
    {
        if (!root)
            return;

        solve(root->right, head);

        root->right = head;

        if (head != NULL)
        {
            head->left = root;
        }

        head = root;

        solve(root->left, head);
    }
    // Function to convert binary tree to doubly linked list and return it.
    Node *bToDLL(Node *root)
    {
        // your code here
        Node *head = NULL;
        solve(root, head);
        return head;
    }
};
