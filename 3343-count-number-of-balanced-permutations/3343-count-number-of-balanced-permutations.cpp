class Solution {
public:
    int mod = 1e9 + 7;

    long long binaryExpo(long long base, long long expo) {
        long long result = 1;
        while (expo > 0) {
            if (expo % 2 == 1) {
                result = (result * base) % mod;
                expo -= 1;
            }
            base = (base * base) % mod;
            expo /= 2;
        }
        return result;
    }

    vector<int> freq;
    vector<int> fact;
    vector<int> ifact;
    int n;
    int target;
    vector<vector<vector<int>>> cache;
    int countBalancedPermutations(string num) {
        n = num.size();
        freq.resize(10);
        fact.resize(n + 1, 1);
        ifact.resize(n + 1, 1);
        int sum = 0;
        for (auto n : num) {
            sum += n - '0';
            freq[n - '0']++;
        }
        if (sum % 2 == 1) {
            return 0;
        }

        target = sum / 2;
        for (int i = 1; i <= n; i++) {
            fact[i] = (1LL * i * fact[i - 1]) % mod;
            ifact[i] = binaryExpo(fact[i], mod - 2);
        }
        cache.resize(10,vector<vector<int>>(n/2+1,vector<int>(sum+1,-1)));
        return solve(0, 0, 0); // Number,takenSize,sum
    }

    int solve(int num, int oddSize, int currSum) {
        int evenSize = n - oddSize;
        if (num == 10) {
            if (oddSize == n / 2 && currSum == target) {
                return (1LL * fact[oddSize] * fact[evenSize]) % mod; 
            } else {
                return 0;
            }
        }

        if(cache[num][oddSize][currSum]!=-1){
            return cache[num][oddSize][currSum];
        }

        long long ans = 0; 
        for (int oddCount = 0; oddCount <= min(freq[num], n / 2 - oddSize); oddCount++) {
            int evenCount = freq[num] - oddCount;
            ans = (ans + (1LL * ifact[oddCount] * ifact[evenCount] % mod) * solve(num + 1, oddSize + oddCount, currSum + num * oddCount) % mod) % mod;
        }
        return cache[num][oddSize][currSum] = ans;
    }
};
