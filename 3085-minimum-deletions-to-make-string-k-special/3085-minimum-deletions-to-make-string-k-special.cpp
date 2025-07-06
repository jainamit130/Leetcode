class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> m;
        for (char c : word) {
            m[c]++;
        }
        
        vector<int> v;
        for (auto it = m.begin(); it != m.end(); ++it) {
            v.push_back(it->second);
        }
        sort(v.begin(), v.end());
        
        int sum_ = 0;
        vector<int> s(v.size(), 0);
        for (int i = v.size() - 1; i >= 0; --i) {
            if (i == v.size() - 1) {
                s[i] = v[i];
            } else {
                s[i] = s[i + 1] + v[i];
            }
        }
        
        int n = v.size();
        int ans = word.size();
        for (int i = 0; i < n; ++i) {
            int lo = i + 1;
            int hi = n - 1;
            if (v[n - 1] - v[i] <= k) {
                ans = min(ans, sum_);
            } else {
                while (lo < hi) {
                    int mid = (lo + hi) / 2;
                    if (v[mid] - v[i] <= k) {
                        lo = mid + 1;
                    } else {
                        hi = mid;
                    }
                }
                int f = 0;
                if (lo < n) {
                    f = s[lo] - (n - lo) * (v[i] + k);
                }
                ans = min(ans, f + sum_);
            }
            sum_ += v[i];
        }
        return ans;
    }
};
