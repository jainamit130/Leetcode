class Solution
{
public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        unordered_map<string, vector<int>> startsWith;
        unordered_map<string, vector<int>> endsWith;
        unordered_map<string, int> palindromes;
        map<pair<string, int>, string> midPalindrome;
        vector<vector<int>> ans;

        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            pair<string, string> suffixPalindrome = extractSuffixPalindrome(word);
            string prefix = suffixPalindrome.first;
            string palindrome1 = suffixPalindrome.second;

            reverse(word.begin(), word.end());
            pair<string, string> reversedSuffixPalindrome = extractSuffixPalindrome(word);
            string suffix = reversedSuffixPalindrome.first;
            string palindrome2 = reversedSuffixPalindrome.second;

            if (prefix == "")
            {
                for (auto &entry : palindromes)
                {
                    ans.push_back({i, entry.second});
                    ans.push_back({entry.second, i});
                }
            }

            if (endsWith.find(prefix) != endsWith.end())
            {
                for (int t = 0; t < endsWith[prefix].size(); t++)
                {
                    // Check if both palindrome stays palindrome when concatenated
                    int index = endsWith[prefix][t];
                    string midPalin = palindrome1 + midPalindrome[{prefix, index}];
                    if (isPalindrome(midPalin))
                    {
                        string subAns = prefix;
                        reverse(prefix.begin(), prefix.end());
                        subAns += midPalin;
                        ans.push_back({i, index});
                    }
                }
            }
            if (startsWith.find(suffix) != startsWith.end())
            {
                for (int t = 0; t < startsWith[suffix].size(); t++)
                {
                    int index = startsWith[suffix][t];
                    string midPalin = palindrome2 + midPalindrome[{suffix, index}];
                    if (isPalindrome(midPalin))
                    {
                        string subAns = suffix;
                        reverse(suffix.begin(), suffix.end());
                        subAns += midPalin;
                        ans.push_back({index, i});
                    }
                }
            }
            startsWith[prefix].push_back(i);
            midPalindrome[{prefix, i}] = palindrome1;
            endsWith[suffix].push_back(i);
            midPalindrome[{suffix, i}] = palindrome2;
            if (isPalindrome(word))
            {
                palindromes[word]=i;
            }
        }
        return ans;
    }

        pair<string, string> extractSuffixPalindrome(string word)
    {
        int j = 0;
        string prefix = "";
        string palindrome = "";
        while (j < word.length())
        {
            if (prefix != "" && isPalindrome(word.substr(j)))
            {
                palindrome = word.substr(j);
                break;
            }
            prefix += word[j];
            j++;
        }
        return {prefix, palindrome};
    }

    bool isPalindrome(const string &word)
    {
        int start = 0;
        int end = word.length() - 1;
        while (start <= end)
        {
            if (word[start] != word[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};