#include <iostream>
using namespace std;

int clearBitsInrange(int n, int i, int j){
    int mask1 = -1<<(i+1);
    int mask2 = (1<<j) - 1;
    int mask = mask1 | mask2;
    n = n & mask;
    return n;
}

int main() {
    int ans = clearBitsInrange(15,2, 1); // ans -> 9
    cout<<ans<<endl;
	return 0;
}