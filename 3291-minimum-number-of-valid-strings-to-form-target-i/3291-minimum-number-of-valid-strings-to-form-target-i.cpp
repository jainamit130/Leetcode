class Trie {
public:
    Trie* children[26];
    Trie() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }

    void constructTree(Trie* node, const string& word) {
        for (char ch : word) {
            if (!node->children[ch - 'a']) {
                node->children[ch - 'a'] = new Trie();
            }
            node = node->children[ch - 'a'];
        }
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        vector<int> cache(target.length(), -1);
        Trie* root = new Trie();
        for (const auto& word : words)
            root->constructTree(root, word);
        
        int result = solve(root, root, target, 0, cache);
        return result == INT_MAX ? -1 : result;
    }

private:
    int solve(Trie* root, Trie* node, const string& target, int index, vector<int>& cache) {
        if (index >= target.length()) return 0;
        
        if (cache[index] != -1) return cache[index];
        
        int ans = INT_MAX;
        Trie* ptr = node;
        
        for (int i = index; i < target.length(); ++i) {
            if (!ptr->children[target[i] - 'a']) break;
            ptr = ptr->children[target[i] - 'a'];
            
            // Recur from the next index
            int subAns = solve(root, root, target, i + 1, cache);
            if (subAns != INT_MAX) {
                ans = min(ans, 1 + subAns);
            }
        }
        
        return cache[index] = ans;
    }
};
