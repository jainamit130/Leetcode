class Solution {
public:
    char findKthBit(int n, int k) {
        return getAns(k,pow(2,n)-1,0) ? '0' : '1';
    }

    bool getAns(int k,int t,int bit) {
        if(k==1) return bit==0;
        int n = (t+1)/2;
        if(k==n) return bit==1;
        else if(k<n) return getAns(k,n-1,bit);
        return getAns(t-k+1,n-1,!bit);
    }
};

/*
0                                       1
0   1   1                               3    
011  1   001                            7
0111001  1   0110001                    15
011100110110001  1   011100100110001    31


2^n - 1


2n+1

<n+1    LEFT
n+1     MIDDLE return 1
>n+1    RIGHT 

*/