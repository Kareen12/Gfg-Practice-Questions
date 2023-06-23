/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution
{
    public:
    
     struct Node* solve( struct Node* &prev, struct Node* &curr){
        if(curr == NULL){
            return prev;
        }
        Node* forward = curr->next;
        curr->next = prev;
        // prev = curr;
        // curr = forward;
        solve(curr, forward);
    }
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
        // code here
        // return head of reversed list
         if(head==NULL || head->next==NULL) return head;
         Node* prev = NULL;
         Node* curr = head;
         head = solve(prev, curr);
         return head;
    }
    
};
    