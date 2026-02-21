class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        vector<int> isPrime(22,1);
        isPrime[0]=0;isPrime[1]=0;
        for(int i=2;i*i<=21;i++) {
            if(!isPrime[i]) continue;
            for(int j=i*i;j<=21;j+=i) {
                isPrime[j]=0;
            }
        }
        for(int i=left;i<=right;i++) {
            int num = i;
            int count = 0;
            while(num) {
                count += num&1;
                num=num>>1;
            }

            ans += isPrime[count];
        }
        return ans;
    }
};