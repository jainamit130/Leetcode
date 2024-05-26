class Solution {
public:
    bool isPowerOfThree(int n) {
        n=abs(n);
        if(n==1 || n==0)
            return false;
        while(n>1){
            if(n%3!=0)
                return false;
            else
                n/=3;
        }
        return true;
    }
};