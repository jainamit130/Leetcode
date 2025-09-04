class Solution {
public:
    bool isAdditiveNumber(string num) {
        return helper(num, 0, -1, -1, LONG_MAX / 100);
    }
    bool helper(string num, int inx, long first, long second, long mx) {
        int n = num.length();
        long val = 0;
        for (int i = inx; i < n; i++) {
            val = val * 10 + (num[i] - '0');
            if (i > inx && num[inx] == '0' || val > mx)
                break;
            if (first == -1) {
                if (helper(num, i + 1, val, second, mx))
                    return true;
            } else if (second == -1) {
                if (helper(num, i + 1, first, val, mx))
                    return true;
            } else {
                if (first + second == val) {
                    if (i == n - 1)
                        return true;
                    return helper(num, i + 1, second, val, mx);
                }
                if (first + second < val)
                    break;
            }
        }
        return false;
    }
};