class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) {
            return false;
        }

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        unordered_set<char> consonants;
        for (char c = 'A'; c <= 'Z'; ++c) {
            if (vowels.find(c) == vowels.end()) {
                consonants.insert(c);
            }
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            if (vowels.find(c) == vowels.end()) {
                consonants.insert(c);
            }
        }

        bool hasVowel = false;
        bool hasConsonant = false;
        for (char c : word) {
            if (!isalnum(c)) {
                return false;
            }
            if (vowels.find(c) != vowels.end()) {
                hasVowel = true;
            }
            if (consonants.find(c) != consonants.end()) {
                hasConsonant = true;
            }
        }

        return hasVowel && hasConsonant;
    }
};
