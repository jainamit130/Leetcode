class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> lis = computeLIS(needle);
        int i=0,j = 0;
        while(i<haystack.length()) {
            if(haystack[i]==needle[j]) {
                i++;j++;
                if(j==needle.length()) return i-needle.length();
            } else {
                j=max(j-1,0);
                j=lis[j];
                if(j==0) i++;
            }
        }
        return -1;
    }

    vector<int> computeLIS(string s) {
        int i=1,j=0;
        int n = s.length();
        vector<int> lis(n);
        while(i<s.length()) {
            // match s[i] and s[j]
            if(s[i]==s[j]) {
                lis[i]=j+1;
                i++;
                j++;
            } else {
                j=max(j-1,0);
                j=lis[j];
                if(j==0) i++;
            }
        }
        return lis;
    }
};


/*

                    j
0   1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18
a   a   b   x   a   a   b   x   c   a   a   b   x   a   a   b   x   a   y
                                                                        i

0   1   0   0   1   2   3   4   0   1   2   3   4   5   6   7   8   5   0



*/