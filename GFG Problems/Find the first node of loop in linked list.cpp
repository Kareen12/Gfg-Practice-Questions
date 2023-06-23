//User function Template for C++

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        // your code here
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
          slow = slow->next;
          fast = fast->next->next;
          if (slow == fast) {
            slow = head;
            while (slow != fast) {
              slow = slow->next;
              fast = fast->next;
            }
            return slow->data;
          }
        }
        return -1;
    }
};