class Solution {
public:
    bool checkDivisibility(int n) {
        long long p1 = 1;
        long long p2 = 0;
        int copyN = n;
        while(n) {
            p2 += n%10;
            p1 = p1 * 1LL * (n%10);
            n/=10;
        }
        
        return copyN%((int)(p1+p2))==0;
    }
};