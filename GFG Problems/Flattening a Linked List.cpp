

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    Node* mergeLL(Node* a, Node* b){
        if(!a) return b;
        if(!b) return a;
        
        Node* ans = 0;
        if(a->data < b->data){
            ans = a;
            a->bottom = mergeLL(a->bottom, b);  
        }
        
        else{
            ans = b;
            b->bottom = mergeLL(a, b->bottom);
        }
        return ans;
    }
    Node *flatten(Node *root)
    {
       // Your code here
       if(!root) return 0;
       Node* finalAns = mergeLL(root, flatten(root->next));
       return finalAns;
    }

