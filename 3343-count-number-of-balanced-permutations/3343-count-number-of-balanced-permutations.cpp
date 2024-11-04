class Solution {
public:
    int mod = 1e9+7;
    long long binaryExpo(int base,int exp) {
        long long result = 1;
        while(exp>0){
            if(exp%2==1){
                result = (base*result)%mod;
                exp-=1;
            }
            base = (1LL * base*base)%mod;
            exp/=2;
        }
        return result;
    }

    vector<int> freq;
    vector<int> fact;
    vector<int> ifact;
    vector<vector<vector<int>>> cache;
    int n;
    int target;
    int countBalancedPermutations(string num) {
        n=num.size();
        freq.resize(10);
        fact.resize(n+1,1);
        ifact.resize(n+1,1);
        int sum = 0;
        for(auto ch:num){
            sum+=ch-'0';
            freq[ch-'0']++;
        }

        if(sum%2==1){
            return 0;
        }

        target = sum/2;
        for(int i=1;i<=n;i++){
            fact[i]=(1LL*i*fact[i-1])%mod;
            ifact[i]=binaryExpo(fact[i],mod-2)%mod;
        }
        cache.resize(10,vector<vector<int>>(n/2+1,vector<int>(target+1,-1)));
        return solve(0,0,0); // Number,Odd Size,CurrSum
    }

    int solve(int num,int oddSize,int currSum) {
        if(num==10){
            if(oddSize==n/2 && currSum==target) {
                int evenSize = n - oddSize;
                return (1LL * fact[oddSize] * fact[evenSize]) % mod;
            } else {
                return 0;
            }
        }

        if(currSum>target){
            return 0;
        }

        if(cache[num][oddSize][currSum]!=-1){
            return cache[num][oddSize][currSum];
        }

        int ans = 0;
        for(int oddCount=0;oddCount<=min(freq[num],n/2-oddSize);oddCount++){
            int evenCount= freq[num]-oddCount;
            ans=(ans+(((1LL * ifact[oddCount]*ifact[evenCount])%mod)*solve(num+1,oddSize+oddCount,currSum+oddCount*num)%mod))%mod;
        }
        return cache[num][oddSize][currSum]=ans;
    }
};


/*


0   1   2   3   4   5   6   7   8   9
2   4   8   6   3   1   7   0   0   2

Odd Set Size= n/2
Even Set Size= (n+1)/2


Total/2 = target

=> Precompute and store the factorials
=> n!/(a!*b!...) => (1/i!)%mod = (i!)^(mod-2) => O(1)
=> I can choose few elements in the odd set and the remaining will go to the even set
=> While inside DP for every call i will compute the permutation of odd set and even set 

    1. Select few count of the numbers in odd set remaning will go in even set = /a!  /b!. Denominator is all set
    2. Base Case = if(number == 10) => (odd Size == n/2 && currSum = target => return (n/2)! * ((n+1)/2)! else 0)

_   _   _   _ ... => Odd Set => 1  1     2  2  3   4   5 => 7!/ (2! * 2!)
_   _   _   _ ... => Even Set




*/