class Solution {
public:
    int maximumSwap(int num) {
        int copyNum = num;
        int exp = -1;
        int maxDigitPow = -1;
        int maxDigit = -1;
        int ans = num;
        while(copyNum){
            int currDigit = copyNum%10;
            exp++;
            int currPow = pow(10,exp); 
            if(maxDigit>=currDigit){
                int subAns = num; 
                subAns-=currDigit*currPow;
                subAns-=maxDigit*maxDigitPow;
                subAns+=currDigit*maxDigitPow;
                subAns+=maxDigit*currPow;
                ans=max(ans,subAns);
            } else {
                maxDigit=currDigit;
                maxDigitPow=currPow;
            }
            copyNum/=10;
        }     
        return ans;
    }
};


/*
0   1   2   3
2   7   3   6

1   3   3   -1


*/