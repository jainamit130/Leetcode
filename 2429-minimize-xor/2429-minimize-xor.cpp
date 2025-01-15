class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int countSetBits1 = 0;
        while(num2) {
            if((num2&1)==1) {
                countSetBits1++;
            }
            num2=num2>>1;
        }

        int countSetBits2 = 0;
        int ans = num1;
        while(num1) {
            if((num1&1)==1) {
                countSetBits2++;
            }
            num1=num1>>1;
        }

        int i = 0;
        if(countSetBits1>countSetBits2) {
            // Convert countSetBits1-countSetBits2 no. of 0s from right side to 1's
            int count = countSetBits1-countSetBits2;
            while(count) {
                if(((ans>>i)&1)==0) {
                    ans |= (1<<i);
                    count--;
                }
                i++;
            }
        } else if(countSetBits1<countSetBits2) {
            // Convert countSetBits2-countSetBits1 no. of 1s from right side to 0's
            int count = countSetBits2-countSetBits1;
            cout<<count<<endl;
            while(count) {
                if(((ans>>i)&1)==1) {
                    ans &= ~(1<<i);
                    count--;
                }
                i++;
            }
        }
        return ans;
    }
};