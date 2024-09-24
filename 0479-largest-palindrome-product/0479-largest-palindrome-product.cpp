class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;

        int max = pow(10, n) - 1;
        int min = max / 10;

        for (int left = max; left > min; --left) {
            long palindrome = left;
            for (int temp = left; temp > 0; temp /= 10) {
                palindrome = palindrome * 10 + (temp % 10);
            }

            for (long n1 = max; n1 * n1 >= palindrome; --n1) {
                if (palindrome % n1 == 0) {
                    long n2 = palindrome / n1;
                    if (n2 <= max && n2 >= min) {
                        return palindrome % 1337;
                    }
                }
            }
        }
        return 9; 
    }
};
