class Solution {
public:
    int smallestNumber(int n, int t) {
        while(1){
            int prod = 1;
            int i =n;
            while(i){
                prod*=(i%10);
                i/=10;
            }

            if(prod%t==0){
                break;
            }
            n++;
        }
        return n;
    }
};