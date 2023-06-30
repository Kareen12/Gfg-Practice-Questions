/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    vector<pair<int, int> > stv;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(stv.size() == 0) return -1;
           return stv.back().second;
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           if(stv.size() == 0) return -1;
           int temp = stv.back().first;
           stv.pop_back();
           return temp;
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
            if(stv.empty()){
                pair<int, int> p = make_pair(x, x);
                stv.push_back(p);
            }
            else{
                pair<int, int> p;
                p.first = x;
                p.second = min(x, stv.back().second);
                stv.push_back(p);
            }
       }
};