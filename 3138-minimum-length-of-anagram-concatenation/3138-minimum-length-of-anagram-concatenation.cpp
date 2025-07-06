class Solution {
public:
    int minAnagramLength(string s) {
        int size = s.length();
        // divisors of size
        for (int i = 1; i<= size; i++) {
            if (size % i == 0) {
                int flag = 0;
                unordered_map<char, int> mp;
                int j = 0;
                for (j = 0; j < i; j++) {
                    mp[s[j]]++;
                }
                // cout << "start" << endl;
                // for (auto [a, b] : mp)
                //     cout << a << " " << b << endl;
                cout << "end" << endl;
                unordered_map<char, int> mp1;
                // cout << "broo"
                //      << " " << j << endl;
                int k = j;
                while (k < size) {
                    if (k - j + 1 <= i) {
                        mp1[s[k]]++;
                        k++;
                    } else {
                        // cout << "start1" << endl;
                        // for (auto [a, b] : mp1)
                        //     cout << a << " " << b << endl;
                        // cout << "end1" << endl;
                        if (mp1 != mp) {
                            flag = 1;
                            break;
                        }
                        mp1.clear();
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