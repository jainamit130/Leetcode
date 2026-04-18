class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0;
        int copyN = n;
        while(n) {
            rev = rev * 10 + n % 10; 
            n/=10;
        }
        return abs(copyN-rev);
    }
};