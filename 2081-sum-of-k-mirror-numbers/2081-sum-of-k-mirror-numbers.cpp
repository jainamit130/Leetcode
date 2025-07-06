class Solution {
public:
    int count = 0;
    long long ans = 0;
    long long kMirror(int k, int n) {
        int len = 1;
        while(count<n) {
            solve(len,"",n,k);
            len++;
        }
        return ans;
    }

    void solve(int len,string num,int n,int k) {
        if(count>=n) return;
        if(num.length()==len/2) {
            string revNum = num;
            reverse(revNum.begin(),revNum.end());
            if(len%2!=0) {
                for (char c = '0'; c <= '9'; ++c) {
                    string full = num + c + revNum;
                    if (full[0] == '0') continue;
                    if (isKbasePalindrome(full, k)) {
                        ans += stoll(full);
                        count++;
                        if (count >= n) return;
                    }
                }
                return;
            } 
            string palindromeNum = ""+num+revNum;
            if(isKbasePalindrome(palindromeNum,k) && count<n) {
                ans += stoll(palindromeNum); count++;
            } 
            return;
        }
        for (char c = '0'; c <= '9'; ++c) {
            if (num.empty() && c == '0') continue;
            solve(len, num + c, n, k);
        }
        return;
    }

    bool isKbasePalindrome(string numStr,int k) {
        long long numn = stoll(numStr);
        string numk = ""; 
        while(numn) {
            numk += to_string(numn%k);
            numn/=k;
        }
        return isPalindrome(numk);
    }

    bool isPalindrome(string numStr) {
        for(int i=0;i<numStr.length()/2;i++) {
            if(numStr[numStr.length()-1-i]!=numStr[i]) return false;
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