class Solution {
public:
    string convertToLower(string &s)
    {
        string result="";
        for(char ch: s) {
            result += tolower(ch);
        }
        return result;
    }

    string changeVowels(string s)
    {
        int n = s.length();
        string vowels = "aeiou";
        for(char &ch: s)
        {
            if(vowels.find(ch) != string::npos) {
                ch = 'a';
            }
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> uniqueWords;
        unordered_map<string,string> caseSensitive, vowelSensitive;
        for(string s: wordlist) {
            uniqueWords.insert(s);
            string lowerCase = convertToLower(s);
            string modifiedString = changeVowels(lowerCase);
            if(!caseSensitive.count(lowerCase)) {
                caseSensitive[lowerCase] = s;
            }
            if(!vowelSensitive.count(modifiedString)) {
                vowelSensitive[modifiedString] = s;
            }
        }

        vector<string> result;
        for(string s: queries) {
            string lowerCase = convertToLower(s);
            string modifiedString = changeVowels(lowerCase);
            if(uniqueWords.find(s) != uniqueWords.end()) {
                result.push_back(s);
            }
            else if(caseSensitive.find(lowerCase) != caseSensitive.end()) {
                result.push_back(caseSensitive[lowerCase]);
            }
            else if(vowelSensitive.find(modifiedString) != vowelSensitive.end()) {
                result.push_back(vowelSensitive[modifiedString]);
            }
            else result.push_back("");
        }
        return result;
    }
};