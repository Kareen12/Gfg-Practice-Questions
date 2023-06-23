/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    Node* findMid(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
     Node* merge(Node* left, Node* right) {
        if(left==NULL)
            return right;
        if(right==NULL)
            return left;
        
        Node* ans=new Node(-1);
        Node* mptr=ans;
        while(left && right){
            if(left->data <= right->data){
                mptr->next=left;
                mptr=left;
                left=left->next;
            }
            else
            {
                mptr->next=right;
                mptr=right;
                right=right->next;
            }
        }
        if(left){
            mptr->next=left;
        }
        if(right){
            mptr->next=right;
        }
        return ans->next;
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL) return head;
        
        Node* mid = findMid(head);
        
        Node* left = head;
        Node* right =mid->next;
        
        mid->next = NULL;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        Node* mergeLL = merge(left, right);
        return mergeLL;
    }
};