//User function template for C++

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         if(head == NULL) return false;
//         ListNode *slow = head;
//         ListNode *fast = head;
        
//         while(fast != NULL){
//             fast=fast->next;
//             if(fast != NULL){
//                 fast = fast->next;
//                 slow = slow->next;
//             }
//             if(slow == fast){
//                 return true;
//             }
//         }
//         return false;
//     }
// };

class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        // if(head == NULL) return false;
        Node *slow = head;
        Node *fast = head;
        
        while(fast != NULL){
            fast=fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
    
};