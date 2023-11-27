class Solution {
  public:
    int binary_to_decimal(string str) {
        // Code here.
        int decimal = 0;
        int n = str.length();
        int i = n-1;
        int j = 0;
        while(i >= 0){
            int bit = str[i]-'0';
            decimal = bit*pow(2,j) + decimal;
            j++;
            i--;
        }
        return decimal;
    }
};