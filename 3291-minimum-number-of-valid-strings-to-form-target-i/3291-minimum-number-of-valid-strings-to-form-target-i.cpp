class TrieNode {
public:
    TrieNode* childs[26];
    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            childs[i] = nullptr;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* temp = root;
        for (char c : word) {
            int idx = c - 'a';
            if (temp->childs[idx] == nullptr) {
                temp->childs[idx] = new TrieNode();
            }
            temp = temp->childs[idx];
        }
    }
};

class Solution {
public:
    int n;
    string target;
    vector<int> dp;

    int solve(int i, TrieNode* root) {
        if (i == n) return 0;
        if (dp[i] != -1) return dp[i];

        TrieNode* temp = root;
        int res = INT_MAX;

        for (int j = i; j < n; ++j) {
            int idx = target[j] - 'a';
            if (temp->childs[idx] == nullptr) break;
            temp = temp->childs[idx];
            int t = solve(j + 1, root);
            if (t != INT_MAX) {
                res = min(res, t + 1);
            }
        }
        return dp[i] = res;
    }

    int minValidStrings(vector<string>& words, string target) {
        Trie trie;
        for (string word : words) {
            trie.insert(word);
        }
        n = target.size();
        this->target = target;
        dp = vector<int>(n, -1);

        int res = solve(0, trie.root);
        return res == INT_MAX ? -1 : res;
    }
};