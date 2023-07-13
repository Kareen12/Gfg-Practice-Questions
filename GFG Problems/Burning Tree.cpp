//User function Template for C++

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
class Solution {
  public:
  int burnTime(Node* targetNode, unordered_map<Node*, Node*> &mp){
      unordered_map<Node*, bool> isVisited;
      isVisited[targetNode] = 1;
      queue<Node*> q;
      q.push(targetNode);
      int time = 0;
      
      while(!q.empty()){
          int n = q.size();
          bool isFireSpread = 0;
          for(int i=0; i<n; i++){
              Node* temp = q.front();
              q.pop();
              
              if(temp->left && !isVisited[temp->left]){
                  q.push(temp->left);
                  isVisited[temp->left] = 1;
                  isFireSpread = 1;
              }
              if(temp->right && !isVisited[temp->right]){
                  q.push(temp->right);
                  isVisited[temp->right] = 1;
                  isFireSpread = 1;
              }
              if(mp[temp] && !isVisited[mp[temp]]){
                  q.push(mp[temp]);
                  isVisited[mp[temp]] = 1;
                  isFireSpread = 1;
              }
          }
          if(isFireSpread) time++;
      }
      return time;
  }
    Node* findTrgetAndCreateMpping(Node* root, int target, unordered_map<Node*, Node*> &mp){
        Node* targetNode = 0;
        queue<Node*> q;
        q.push(root);
        mp[root] = 0;
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            if(temp->data == target){
                targetNode = temp;
            }
            
            if(temp->left){
                q.push(temp->left);
                mp[temp->left] = temp;
            }
            if(temp->right){
                q.push(temp->right);
                mp[temp->right] = temp;
            }
        }
        return targetNode;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node*, Node*> mp;
        Node* targetNode = findTrgetAndCreateMpping(root, target, mp);
        return burnTime(targetNode, mp);
    }
};