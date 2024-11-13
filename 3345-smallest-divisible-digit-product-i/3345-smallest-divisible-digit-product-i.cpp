class Solution {
public:
    int smallestNumber(int n, int t) {
        int prod;
        while(1){
            prod = 1;
            int copy = n;
            while(copy) {
                prod*=copy%10;
                copy/=10;
            }

            if(prod%t==0){
                break;
            }
            n++;
        }
        return n;
    }
};