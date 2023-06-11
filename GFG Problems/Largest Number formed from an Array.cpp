//User function template for C++
class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	
	static bool mycomp(string a, string b){
        string t1 = a+b;
        string t2 = b+a;
        //The statement below holds true when a is greater than b and false for otherwise
        return t1>t2;
    }
	string printLargest(vector<string> &arr) {
	    // code here
        sort(arr.begin(),arr.end(), mycomp);
        
        if(arr[0] == "0") return "0";
        
        string ans = "";
        for(int i=0;i<arr.size();i++){
            ans+=arr[i];
        }
        return ans;
	    
	}
};