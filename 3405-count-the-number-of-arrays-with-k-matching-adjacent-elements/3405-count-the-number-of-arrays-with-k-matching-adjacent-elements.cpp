class Solution {
public:
    int mod = 1e9+7;
    vector<long long> factorials;
    int countGoodArrays(int n, int m, int k) {
        factorials.resize(n+1,1);
        for(int i=2;i<=n;i++) {
            factorials[i] = (factorials[i-1]* i) % mod;
        }

        long long ans = nCr(n-1,k) % mod;
        ans = (ans * m)%mod;
        ans = (ans * binaryExp(m-1,n-1-k))%mod;
        return ans;
    }

    long long nCr(int n,int r) {
        return factorials[n] * inverseFact(factorials[r],mod) % mod * inverseFact(factorials[n-r],mod) % mod; 
    }

    long long inverseFact(long long n, int mod) {
        return binaryExp(n,mod-2) % mod;
    }

    long long binaryExp(long long base,int exp) {
        long long prod = 1;
        while(exp>0) {
            if(exp%2==1) {
                prod = (prod * base) % mod;
            }
            base = (base * base) % mod;
            exp/=2; 
        }
        return prod;
    }
};

/*

m*    n-1ck * (m-1)^(n-1-k)





*/