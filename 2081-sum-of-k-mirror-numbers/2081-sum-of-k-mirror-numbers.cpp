class Solution {
public:
    int count = 0;
    long long ans = 0;

    long long kMirror(int k, int n) {
        int len = 1;
        while (count < n) {
            dfs(len, "", k, n);
            len++;
        }
        return ans;
    }

    void dfs(int len, string num, int k, int n) {
        if (count >= n) return;
        if (num.size() == len / 2) {
            string rev = num;
            reverse(rev.begin(), rev.end());

            if (len % 2 == 0) {
                string full = num + rev;
                if (isKbasePalindrome(full, k)) {
                    ans += stoll(full);
                    count++;
                }
            } else {
                for (char c = '0'; c <= '9'; ++c) {
                    string full = num + c + rev;
                    if (full[0] == '0') continue;
                    if (isKbasePalindrome(full, k)) {
                        ans += stoll(full);
                        count++;
                        if (count >= n) return;
                    }
                }
            }
            return;
        }

        for (char c = '0'; c <= '9'; ++c) {
            if (num.empty() && c == '0') continue;
            dfs(len, num + c, k, n);
        }
    }

    bool isKbasePalindrome(string numStr, int k) {
        long long num = stoll(numStr);
        string baseK = "";
        while (num > 0) {
            baseK += char('0' + num % k);
            num /= k;
        }
        return isPalindrome(baseK);
    }

    bool isPalindrome(const string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};

/*

Approach:

1. Generate all the palindromic numbers till the count of valid k mirror becomes == n
2. check for every generated number in basek to check if it a palindrome in base k as well
3. keep track of a total valid count till that point for stopping condition.

Time complexity

_  _  _  _  .... _  _

5 => 9 * 10^4 * 

367 => 367/5 => 2
73 => 73/5 => 3
14 => 14/5 => 4
2 =>          2


2*125 + 4*25 + 3*5 + 2



*/