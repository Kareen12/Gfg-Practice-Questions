
/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void insertSorted(stack<int> &s, int temp){
    
    if(s.empty() || s.top() < temp){
        s.push(temp);
    }
    else{
        int x = s.top();
        s.pop();
        insertSorted(s, temp);
        s.push(x);
    }
    
}
void reverse(stack<int> &s){
    
    if(s.empty()){
       return;
   }
   
   int temp = s.top();
   s.pop();
   
   reverse(s);
   
   insertSorted(s,temp);
   
}
void SortedStack :: sort()
{
   //Your code here
//   int target = s.top();
   reverse(s);
   
}
    