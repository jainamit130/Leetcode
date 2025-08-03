class Solution {
public:
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        int blockSize = sqrt(n);

        vector<int> ans(q);
        vector<tuple<int, int, int, int>> qs;
        for (int i = 0; i < q; ++i) {
            int l = queries[i][0];
            int r = queries[i][1];
            int t = queries[i][2];
            qs.emplace_back(l / blockSize, r, l, i);
        }

        sort(qs.begin(), qs.end());
        unordered_map<int, int> freq;

        int L = 0, R = -1;
        for (auto& [block, r, l, idx] : qs) {
            int threshold = queries[idx][2];
            while (R < r) freq[nums[++R]]++;
            while (R > r) freq[nums[R--]]--;
            while (L < l) freq[nums[L++]]--;
            while (L > l) freq[nums[--L]]++;

            int best = -1, bestFreq = 0;
            for (auto& [val, f] : freq) {
                if (f >= threshold && (f > bestFreq || (f == bestFreq && val < best))) {
                    best = val;
                    bestFreq = f;
                }
            }
            ans[idx] = best;
        }
        return ans;
    }
};

/*



0   1   2   3   4   5   6
3   2   3   2   3   2   3
        L
                        R

3 -> 2
2 -> 3


0           1           2           3
3   2       3   2       3   2       3   M

2 -> 1      2 -> 1      2 -> 1      3 -> 1
3 -> 1      3 -> 1      3 -> 1      

3 -> 4
2 -> 3

1   5   2 => 0
0   6   4 => 0
3   3   1 => 1
2   4   1 => 1


*/