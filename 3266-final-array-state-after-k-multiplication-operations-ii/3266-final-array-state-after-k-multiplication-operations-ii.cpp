long long modExp(int base, int exp, int mod) {
    if (exp == 0) {
        return 1;  
    }
    
    long long half = modExp(base, exp / 2, mod);
    half = (half * half) % mod;
    
    if (exp % 2 != 0) {
        half = (half * base) % mod;  
    }
    
    return half;
}


class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;  
        }

        int mod = 1e9 + 7;
        int m = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (int i = 0; i < n; i++) {
            minHeap.push({nums[i], i});
        }

        while (k > 0 && (long long)minHeap.top().first * multiplier <= m) {
            auto [value, index] = minHeap.top();
            minHeap.pop();
            value = (value * multiplier) % mod;
            minHeap.push({value, index});
            k--;
        }

        vector<pair<int, int>> vals;
        while (!minHeap.empty()) {
            vals.push_back(minHeap.top());
            minHeap.pop();
        }

        int q = k / n;
        int remK = k % n;

        for (int i = 0; i < n; i++) {
            vals[i].first = (long long)vals[i].first * modExp(multiplier, q, mod) % mod;
        }

        for (int i = 0; i < remK; i++) {
            vals[i].first = (long long)vals[i].first * multiplier % mod;
        }

        vector<int> result(n);
        for (auto& [value, index] : vals) {
            result[index] = value;
        }

        return result;
    }
};