int clearIthBit(int &n, int i){
    int mask = ~(1<<i);
    n = n & mask;
    return n;
}

int modifytIthBit(int &n, int i, int target){
    clearIthBit(n, i);
    int mask = target<<i;
    n = n | mask;
    return n;
}

int main() {
    int n = 10;
    int ans = modifytIthBit(n, 0, 1); // ans -> 11
    cout<<ans<<endl;
	return 0;
}