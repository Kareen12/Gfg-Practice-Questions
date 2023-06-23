
/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    Node* ans = new Node(-1);
    Node* mptr = ans;
    
    while(head1 && head2){
        if(head1->data <= head2->data){
            mptr->next=head1;
            mptr = head1;
            head1 = head1->next;
        }
        else{
             mptr->next=head2;
             mptr = head2;
             head2 = head2->next;
        }
    }
    
    if(head1){
        mptr->next = head1;
    }
     if(head2){
        mptr->next = head2;
    }
    return ans->next;
}  