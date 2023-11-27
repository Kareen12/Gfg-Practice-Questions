// BRUTE FORCE
class Solution {
  public:
    int setBits(int n) {
        //Write Your Code here
        int count = 0;
        // int lastBit = (n & 1);
        while(n != 0){
            if((n & 1) == 1)
                count++;
            n = n>>1;
        }
        return count;
    }
};

// BETTER APPROACH
class Solution {
  public:
    int setBits(int n) {
        //Write Your Code here
        int count = 0;
        while(n != 0){
            n = (n & (n-1));
            count++;
        }
        return count;
    
    }
};