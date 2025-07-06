class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int ans=0;
        for(int i=3;i>=0;i--){
            int digit=9;
            digit=min(digit,num1%10);
            num1/=10;
            digit=min(digit,num2%10);
            num2/=10;
            digit=min(digit,num3%10);
            num3/=10;
            int subAns = pow(10,3-i);
            subAns= subAns*digit + ans;
            ans=subAns;
        }
        return ans;
    }
};

/*
num1 = 1, num2 = 10, num3 = 1000

0   0   0   1
0   0   1   0   
1   0   0   0
---------------
0   0   0   0 => 0



*/