class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        if(n==0)
            return x;
        vector<int> unsetBits(64,0);
        long long t=1;
        for(int i=63;i>=0;i--){
            if((t<<(63-i)) & x){
                unsetBits[i]=1;
            }
        }
        vector<int> unsetBits1=unsetBits;
        long long res=1;
        while(n){
            if(n==1){
                unsetBits1=unsetBits;
                int k=63;
                for(int i=63;i>=0;i--){
                    if(unsetBits1[i]==0){
                        unsetBits1[i]=unsetBits1[i]|((res>>(63-k)) & 1);
                        k--;
                    }
                }
            }
           res++;
            n--;
        }
        long long ans=0;
        for(int i=0;i<64;i++){
            ans= (ans<<1) | unsetBits1[i];
        }
        return ans;
    }
};