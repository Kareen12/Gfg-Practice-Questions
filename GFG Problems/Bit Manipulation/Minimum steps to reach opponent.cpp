// this ques is same as climbing stairs just the difference is person can take inly 2^n steps
#include <iostream>
using namespace std;

int minSteps(int n){
    int count = 0;
    while(n != 0){
        n = n & (n-1);
        count++;
    }
    return count;
}

int main() {
    int ans = minSteps(5);
    cout<<ans<<endl;
	return 0;
}