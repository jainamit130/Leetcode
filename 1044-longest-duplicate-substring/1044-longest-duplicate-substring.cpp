class Solution {
public:
    int mod = 1e9 + 7;
    using ll = long long;

    // Function to calculate 26^m for the rolling hash window size
    ll calMaxWeight(int radix, int windowSize, int mod) {
        ll ans = 1;
        for (int i = 1; i <= windowSize; i++) {
            ans = (ans * 1ll * radix) % mod;
        }
        return ans;
    }

    // Function to calculate hash value for a string
    ll getHashVal(int radix, string str, int mod) {
        ll ans = 0;
        ll factor = 1;
        for (int i = str.length() - 1; i >= 0; i--) {
            ans = (ans + (factor * (str[i] - 'a')) % mod) % mod;
            factor = (factor * 26) % mod;
        }
        return ans;
    }

    // Main function for longest duplicate substring using binary search
    string longestDupSubstring(string s) {
        string ans = "";
        int start = 1;
        int end = s.length() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            string duplicatedWord = rollingHash(s, mid);
            cout << mid << " " << duplicatedWord << endl;
            if (duplicatedWord != "") {
                ans = duplicatedWord;
                start = mid + 1;  // Try to find a longer duplicate
            } else {
                end = mid - 1;    // Try to find a shorter duplicate
            }
        }
        return ans;
    }

    // Rolling hash function to check for duplicates
    string rollingHash(string s, int mid) {
        unordered_map<ll, vector<int>> mp;
        int i = 0, j = mid;
        string currWord = s.substr(i, mid);
        ll hashVal = getHashVal(26, currWord, mod);
        ll maxWt = calMaxWeight(26, mid-1, mod);
        
        mp[hashVal].push_back(i); // Store the index of the first word
        
        while (j < s.length()) {
            // Remove the first character from the window and add the new character at the end
            hashVal = (hashVal - (s[i] - 'a') * maxWt % mod + mod) % mod;
            hashVal = (hashVal * 26 + (s[j] - 'a')) % mod;
            
            // Check if this hash value already exists in the map
            if (mp.find(hashVal) != mp.end()) {
                // Check if the substring matches the one from the map (to avoid spurious hits)
                for (int index : mp[hashVal]) {
                    string substr = s.substr(index, mid);
                    if (substr == s.substr(i + 1, mid)) {
                        return substr;  // Found duplicate substring
                    }
                }
            }
            
            mp[hashVal].push_back(i + 1); // Store the index for future comparison
            i++; j++; // Slide the window
        }
        return "";  // No duplicate found for this length
    }
};



/*




the length can vary from 1 - s.length()-1

bbbbb

aaaabbbb



*/