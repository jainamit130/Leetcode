class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10, right = 1e10;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (countProducts(nums1, nums2, mid) < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    long long countProducts(vector<int>& nums1, vector<int>& nums2, long long target) {
        long long count = 0;
        for (int num1 : nums1) {
            if (num1 == 0) {
                if (target >= 0) count += nums2.size();
                continue;
            }

            int low = 0, high = nums2.size();
            while (low < high) {
                int mid = (low + high) / 2;
                long long prod = 1LL * num1 * nums2[mid];
                if (prod <= target) {
                    if (num1 > 0) low = mid + 1;
                    else high = mid;
                } else {
                    if (num1 > 0) high = mid;
                    else low = mid + 1;
                }
            }

            count += (num1 > 0) ? low : (nums2.size() - low);
        }
        return count;
    }
};

/*

-2  -1  0   1   2



-3  -1  2   4   5



-10    ----    10


6   3   0   -3  -6
2   1   0   -1  -2
--------------------
-6  -3  -2  -1  0   0   1   3   2   6


-4  -2  0   2   4
-8  -4  0   4   8
-10 -5  0   5   10

-------------------

-10 -8  -5  -4  -4  -2  0   0   0   2   4   4   5   8   10

*/