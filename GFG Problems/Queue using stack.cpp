//User function Template for C++

class Queue {
    stack<int> input, output;
public:

    void enqueue(int x) {
        input.push(x);
    }

    int dequeue() {
        int top = -1;
        if(!output.empty()){
            top = output.top();
            output.pop();
        }
        else{
            while(!input.empty()){
               output.push(input.top());
               input.pop();
             }
            top = output.top();
            output.pop();
        }
        return top;
    }
};