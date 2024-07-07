#include <iostream>
using namespace std;

int clearIthBit(int n, int i){
    int mask = ~(1<<i);
    int ans = n & mask;
    return ans;
}

int main() {
    int ans = clearIthBit(10,1); // ans -> 8
    cout<<ans<<endl;
	return 0;
}