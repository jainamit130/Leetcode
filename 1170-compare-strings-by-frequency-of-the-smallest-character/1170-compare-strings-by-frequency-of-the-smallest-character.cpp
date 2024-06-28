class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> wordsCount(words.size(), 0); // Initialize wordsCount with size of words vector
        int j = 0;
        for (auto& word : words) {
            wordsCount[j] = function(word);
            j++;
        }

        vector<int> ans(queries.size(), 0); // Initialize ans with size of queries vector
        j = 0;
        for (auto& q : queries) {
            int num=function(q);
            for(auto c:wordsCount){
                if(num<c){
                    ans[j]++;
                }
            }
            j++;
        }
        return ans;
    }

        int function(string word) {
        vector<int> freq(26, 0); // Initialize freq vector with 26 elements, all set to 0
        for (auto& ch : word) {
            if (ch >= 'a' && ch <= 'z') { // Ensure character is within 'a' to 'z' range
                freq[ch - 'a']++;
            }
        }
        int i = 0;
        for (i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                // Return the frequency of the first character found in alphabetical order
                return freq[i];
            }
        }
        return 0; // If no valid characters found, return 0
    }
};