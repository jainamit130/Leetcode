class Solution {
public:
    int minAnagramLength(string s) {
        int size = s.length();
        for (int i = 1; i <= size; i++) {
            if (size % i == 0) {
                int flag = 0;
                vector<int> mp(26, 0); // Vector to store character counts
                int j = 0;
                for (j = 0; j < i; j++) {
                    mp[s[j] - 'a']++;
                }
                vector<int> mp1(26, 0); // Vector to store character counts for current window
                int k = j;
                while (k < size) {
                    if (k - j + 1 <= i) {
                        mp1[s[k] - 'a']++;
                        k++;
                    } else {
                        if (mp1 != mp) {
                            flag = 1;
                            break;
                        }
                        fill(mp1.begin(), mp1.end(), 0);
                        j = k;
                    }
                }
                if (!flag && mp1 != mp) {
                    flag = 1;
                }
                if (!flag)
                    return i;
            }
        }
        return size;
    }
};

/*

c   d   e   f
        j
            k

mp => 
c 1
d 1


*/