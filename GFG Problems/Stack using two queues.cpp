//USING ONE QUEUE

/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
        for(int i=0; i<q1.size()-1; i++){
            int fr = q1.front();
            q1.pop();
            q1.push(fr);
        }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code 
       if(q1.empty()) return -1;
       
       int top = q1.front();
       q1.pop(); 
       return top;
}

//USING TWO QUEUES

/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
        // Your Code
        // push in q2
        q2.push(x);
        // then put all the elements of q1 to q2 
        while(!q1.empty()){
          q2.push(q1.front());
          q1.pop();
        }
        // then put them back to q1
         while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
       
        if(q1.empty()){
           return -1;
         }
          int top=q1.front();
          q1.pop();
          return top;
}