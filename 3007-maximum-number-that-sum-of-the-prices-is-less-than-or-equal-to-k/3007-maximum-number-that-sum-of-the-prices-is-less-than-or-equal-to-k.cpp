class Solution {
public:
    typedef long long ll;
    vector<ll> bitCount;
    void getSetBitsCount(ll num){
        if(num==0){
            return;
        }

        if(num==1){
            bitCount[0]++;
            return;
        }

        if(num==2){
            bitCount[0]++;
            bitCount[1]++;
            return;
        }

        int bitLength = log2(num);
        ll border = pow(2,bitLength);
        bitCount[bitLength]=num-border+1;
        for(int i=0;i<bitLength;i++){
            bitCount[i]+=(border/2);
        }
        getSetBitsCount(num-border);
        return;
    }

    long long findMaximumNumber(long long k, int x) {
        ll left=0;
        ll right=1e15;
        ll ans=0;
        ll result=0;
        while(left<=right){
            bitCount=vector<ll>(65,0);
            ll mid = left+(right-left)/2;
            getSetBitsCount(mid);
            ll total=0;
            for(int i=0;i<log2(mid)+1;i++){
                if((i+1)%x==0){
                    total+=bitCount[i];
                }
            }
            if(total<=k){
                if(total>ans){
                    ans=total;
                    result=mid;
                }
                left=mid+1;
            } else{
                right=mid-1;
            } 
        }
        return result;
    }
};