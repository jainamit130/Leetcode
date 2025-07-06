#include <string>
#include <unordered_set>
#include <cctype>

class Solution {
public:
    int numberOfSpecialChars(std::string word) {
        int count = 0;
        unordered_set<char> lowercase;
        unordered_set<char> uppercase;

        for (char ch : word) {
            if (islower(ch)) {
                lowercase.insert(ch);
            } else if (isupper(ch)) {
                uppercase.insert(ch);
            }
        }

        for (char ch : lowercase) {
            if (uppercase.count(toupper(ch))) {
                count++;
            }
        }

        return count;
    }
};
