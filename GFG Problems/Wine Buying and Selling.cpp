//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& Arr, int N){
      vector<int>Neg;
      vector<int>Pos;
      for(int i=0;i<N;i++)
      {
          if(Arr[i]>0)
          {
             Pos.push_back(i);
          }
          else
             Neg.push_back(i);
      }
      long long int i=0,j=0;
      long long int ans=0;
      while(i<Neg.size())
      {
          if(abs(Arr[Neg[i]])==Arr[Pos[j]])
          {
              ans+=abs(Neg[i]-Pos[j])*Arr[Pos[j]];
              j++;
              i++;
          }
          else if(abs(Arr[Neg[i]])<Arr[Pos[j]])
          {
              ans+=abs(Neg[i]-Pos[j])*abs(Arr[Neg[i]]);
              Arr[Pos[j]]=Arr[Pos[j]]+Arr[Neg[i]];
              i++;
          }
          else
          {
              ans+=abs(Neg[i]-Pos[j])*Arr[Pos[j]];
              Arr[Neg[i]]=Arr[Neg[i]]+Arr[Pos[j]];
              j++;
          }
      }
      return (ans);
  }
};

