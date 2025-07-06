class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }
        unordered_map<char, int> freq1, freq2;
        unordered_set<char> c1, c2;
        for (auto ch : word1) {
            freq1[ch]++;
            c1.insert(ch);
        }

        for (auto ch : word2) {
            freq2[ch]++;
            c2.insert(ch);
        }

        if (c1 != c2) {
            return false;
        }

        vector<int> count1, count2;
        for (auto p : freq1) {
            count1.push_back(p.second);
        }

        for (auto p : freq2) {
            count2.push_back(p.second);
        }

        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());
        return count1 == count2;
    }
};