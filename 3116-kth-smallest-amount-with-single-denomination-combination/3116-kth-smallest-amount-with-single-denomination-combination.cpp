class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long l=1; long long r = 25+25*2*(1e9);
        long long ans = 0;
        while(l<=r){
            long long mid = (l + r)/2;
            long long cnt = countLessThanOrEqualToX(coins,mid);
            if(k>cnt)
                l=mid+1;
            else {
                ans = mid;
                r=mid-1;
            }
        }   
        return ans;
    }

    long long countLessThanOrEqualToX(vector<int>& coins,long long x){
        int m = coins.size();
        int allOnes = (1<<m)-1;
        long long cnt=0;
        for(int mask=1;mask<=allOnes;mask++){
            long long setBitsLcm = 1;
            for(int j=0;j<m;j++){
                if(mask&(1LL<<j)){
                    setBitsLcm = lcm(setBitsLcm,coins[j]);
                }
            }
            if(__builtin_popcount(mask) & 1){
                cnt+=x/setBitsLcm;
            } else {
                cnt-=x/setBitsLcm;
            }
        }
        return cnt;
    }
};