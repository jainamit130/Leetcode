class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& wt) {
    long long l = 1, r = 100000000000LL * mountainHeight / wt.size();

    while (l < r) {
        long long m = (l + r) / 2;
        long long h = 0; // Total height reduction

        // Accumulate height reductions using a loop
        for (int t : wt) {
            h += static_cast<long long>(sqrt(m / static_cast<double>(t) * 2 + 0.25) - 0.5);
        }

        if (h < mountainHeight)
            l = m + 1;
        else
            r = m;
    }

    return l;
}

};
