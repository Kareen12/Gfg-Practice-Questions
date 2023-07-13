vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int N, long long int K) {
               
       deque<int> dq; 
       vector<long long> ans;
       
       for(int i=0; i<K; i++){
           if(arr[i]<0){
               dq.push_back(i);
           }
       }
       
       for(int i=K; i<N; i++){
           if(dq.empty()){
               ans.push_back(0);
           }
           else{
               ans.push_back(arr[dq.front()]);
           }
           
           while(!dq.empty() && i-dq.front() >= K){
               dq.pop_front();
           }
           
           if(arr[i]<0){
               dq.push_back(i);
           }
       }
       //Last unprocessed window
      if(!dq.empty()){
          ans.push_back(arr[dq.front()]);
      }
      else{
          ans.push_back(0);
      }
      
      return ans;
 }