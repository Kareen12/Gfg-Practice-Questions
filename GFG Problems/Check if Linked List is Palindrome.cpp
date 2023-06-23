/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
      Node* reverse(Node* head){
            Node* prev = NULL;
            Node* curr = head;
            Node* forward = NULL;
            
            while(curr != NULL){
                forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
            }
            return prev;
        };
        //Function to check whether the list is palindrome.
        bool isPalindrome(Node *head)
        {
            //Your code here
            if(head == NULL || head->next == NULL) return 1;
            
            //step 1: finding the middle of the linked list
            Node* slow = head;
            Node* fast = head->next;
            
            while(fast!=NULL && fast->next!=NULL){
                fast=fast->next->next;
                slow=slow->next;
            }
            
            Node* reversedHead = reverse(slow->next);
            slow->next = reversedHead;
            
            Node* temp1 = head;
            Node* temp2 = reversedHead;
            
            while(temp2 != NULL){
                if(temp1->data != temp2->data){
                    return 0;
                }
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            return 1;
        }
};
