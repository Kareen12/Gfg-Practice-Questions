// METHOD 1
void toBinary(int N)
{
    // your code here
    int binaryNo = 0;
    int i = 0;
    while(N > 0){
        int bit = N % 2;
        binaryNo = bit * pow(10, i++) + binaryNo;
        N = N/2;
    }
    cout<<binaryNo;
        
}

// METHOD 2
void toBinary(int N)
{
    // your code here
    int binaryNo = 0;
    int i = 0;
    while(N > 0){
        int bit = N & 1;
        binaryNo = bit * pow(10, i++) + binaryNo;
        N = N>>1;
    }
    cout<<binaryNo;
        
}