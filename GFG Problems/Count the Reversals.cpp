

int countRev (string s)
{
    // your code here
    if(s.length() & 1) return -1;
    stack<char> st;
    for(int i=0; i<s.length() ;i++){
        if(s[i] == '{'){
            st.push('{');
        }
        else if(!st.empty() && st.top() == '{'){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }
    
    int count = 0;
    while(!st.empty()){
        if(st.top() == '{'){
            st.pop();
            if(st.top() == '{'){
                count+=1;
                st.pop();
            }
            else if(st.top() == '}'){
                count+=2;
                st.pop();
            }
        }
        else if(st.top() == '}'){
            st.pop();
            if(st.top() == '{'){
                count+=2;
                st.pop();
            }
            else if(st.top() == '}'){
                count+=1;
                st.pop();
            }
        }
    }
    return count;
}