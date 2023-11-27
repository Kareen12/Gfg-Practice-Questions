#include <iostream>
using namespace std;

int clearLastIBit(int n, int i){
    int mask = -1<<i;
    int ans = n & mask;
    return ans;
}

int main() {
    int ans = clearLastIBit(7,2); // ans -> 4
    cout<<ans<<endl;
	return 0;
}