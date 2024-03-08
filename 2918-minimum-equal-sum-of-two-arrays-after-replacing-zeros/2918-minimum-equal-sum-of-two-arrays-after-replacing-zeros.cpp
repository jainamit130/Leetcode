class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int c1 = 0;
        int c2 = 0;
        long int t1 = 0;
        long int t2 = 0;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == 0) {
                t1 += 1;
                c1++;
            }

            t1 += nums1[i];
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (nums2[i] == 0) {
                t2 += 1;
                c2++;
            }
            t2 += nums2[i];
        }
        if (t1 < t2) {
            if (c1 == 0)
                return -1;
        }
        if (t1 > t2) {
            if (c2 == 0)
                return -1;
        }
        return max(t1, t2);
    }
};