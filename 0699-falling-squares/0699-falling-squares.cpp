class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> res(n);
        int maxHeight = 0;
        vector<tuple<int, int, int>>
            layers; // intervals: {a,b,height} -- max capacity = 1000
        for (int i = 0; i < n; i++) { // O(1000)
            int left = positions[i][0], sidelen = positions[i][1];
            int ca = left, cb = left + sidelen, ch = sidelen;
            int mh = 0;
            for (auto [na, nb, nh] : layers) { // O(1000)
                if (hasOverlap(ca, cb, na, nb)) {
                    mh = max(mh, nh);
                }
            }
            maxHeight = max(maxHeight, mh + ch);
            res[i] = maxHeight;
            layers.push_back({ca, cb, mh + ch});
        }
        return res;
    }

private:
    // return true if the two intervals overlap
    bool hasOverlap(int start1, int end1, int start2, int end2) {
        if (start1 < end2 and end1 > start2)
            return true; // starts before other ends, and ends after the start
        return false;
    }
};