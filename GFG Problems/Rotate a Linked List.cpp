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


class Solution
{
    public:
    // int getLength(Node* head){
    //     int len = 0;
    //     Node* demo = head;
    //     while(demo){
    //         len++;
    //         demo = demo->next;
    //     }
    //     return len;
    // }
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        if(!head) return 0;
        
        Node* tail = head;
        
        int len = 1;
        Node* demo = head;
        while(demo->next){
            len++;
            demo = demo->next;
        }
        
        tail = demo;
        demo = head;
        int modifiedK = k % len;
        
        if(modifiedK == 0) return head;
        
        for(int i=0; i<modifiedK; i++){
            head = demo->next;
            tail->next = demo;
            demo->next = NULL;
            tail = tail->next;
            demo = head;
        }
        return head;
    }
    
};
    
