class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& wt) {
    long long l = 1, r = 1e18;

    while (l < r) {
        long long m = (l + r) / 2;
        long long h = 0; 

        for (int t : wt) {
            h += (long long)(sqrt(m / (double)(t) * 2 + 0.25) - 0.5);
        }

        if (h < mountainHeight)
            l = m + 1;
        else
            r = m;
    }

    return l;
}

};
