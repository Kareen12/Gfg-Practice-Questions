#include<iostream>
using namespace std;

int findIthBit(int n, int i){
    int mask = 1<<i;
    int ans = n & mask;
    if(ans == 0)
        return 0;
    else
        return 1;
}

int main(){
    int ans = findIthBit(10, 3); // ans -> 1
    cout<<ans<<endl;
}