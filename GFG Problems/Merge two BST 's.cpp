/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
       //Your code here
       vector<int> ans;
       stack<Node*> s1, s2;
       Node* a = root1;
       Node* b = root2;
       while(a || b || !s1.empty() || !s2.empty()){
           while(a){
               s1.push(a);
               a = a->left;
           }
           while(b){
               s2.push(b);
               b = b->left;
           }
           
        //   if(s1.empty() && s2.empty()){
        //       break;
        //   }
           
        //   if(s1.empty() && !s2.empty()){
        //       while(s2.empty()){
        //           auto top = s2.top();
        //           ans.push_back(top->data);
        //           s2.pop();
        //       }
        //   }
           
        //   if(!s1.empty() && s2.empty()){
        //       while(s1.empty()){
        //           auto top = s1.top();
        //           ans.push_back(top->data);
        //           s1.pop();
        //       }
        //   }
        //   auto atop = s1.top();
        //   auto btop = s2.top();
           
           if(s2.empty() || (!s1.empty() && s1.top()->data <= s2.top()->data)){
               auto atop = s1.top();
               ans.push_back(atop->data);
               s1.pop();
               a = atop->right;
           }
           else{
               auto btop = s2.top();
               ans.push_back(btop->data);
               s2.pop();
               b = btop->right;
           }
       }
       return ans;
    }
};