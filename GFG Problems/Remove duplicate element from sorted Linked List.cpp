

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
 // your code goes here
    Node* curr = head;
    while(curr != NULL){
        if( (curr->next != NULL) && (curr->data == curr->next->data)){
            // ListNode* forward = curr->next;
            curr->next = curr->next->next;
            // forward->next = NULL;  
            }
            else{
                curr = curr->next;
            }
        }
        return head;
}