#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    int sum;
	    sum=(a[n-1]*a[n-1]);
	    int flag = -1;
	    for(int i=n-2;i>=0;i--)
	    {
	        
	        sum+= flag*(a[i]*a[i]);
	        flag*=-1;
	     }
	   
	   
	     cout<<sum<<endl;
	    
	    
	   }
	return 0;
}