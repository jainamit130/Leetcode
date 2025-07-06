// Design Search Autocomplete System
// Problem Link: https://leetcode.ca/all/642.html#google_vignette
// Leetcode Link: https://leetcode.com/problems/design-search-autocomplete-system/description/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class Trie
{
public:
    unordered_map<char, Trie *> children;
    bool end;

    Trie()
    {
        end = false;
    }

    void insert(Trie *root, string word)
    {
        for (auto ch : word)
        {
            if (root->children.find(ch) == root->children.end())
            {
                root->children[ch] = new Trie();
            }
            root = root->children[ch];
        }
        root->end = true;
    }

    vector<string> search(Trie *root, string word)
    {
        vector<string> searchResults;
        for (auto ch : word)
        {
            if (root->children.find(ch) != root->children.end())
            {
                root = root->children[ch];
            }
            else
            {
                return {};
            }
        }
        dfs(root, word, searchResults);
        return searchResults;
    }

    void dfs(Trie *root, string prefix, vector<string> &searchResults)
    {
        if (root->end)
        {
            searchResults.push_back(prefix);
            return;
        }

        for (auto it = root->children.begin(); it != root->children.end(); it++)
        {
            Trie *newTrie = it->second;
            char ch = it->first;
            if (root->children.find(ch) == root->children.end())
            {
                continue;
            }
            else
            {
                dfs(root->children[ch], prefix + ch, searchResults);
            }
        }
        return;
    }
};

typedef pair<int, string> pis;

struct comparator
{
    bool operator()(const pis &lhs, const pis &rhs)
    {
        if (lhs.first == rhs.first)
        {
            return lhs.second < rhs.second;
        }
        return lhs.first > rhs.first;
    }
};

class AutocompleteSystem
{
    Trie *root;
    unordered_map<string, int> freq;
    string currentString = "";

public:
    AutocompleteSystem(vector<string> &sentences, vector<int> &times)
    {
        root = new Trie();
        for (int i = 0; i < sentences.size(); i++)
        {
            root->insert(root, sentences[i]);
            freq[sentences[i]] = times[i];
        }
    }

    ~AutocompleteSystem()
    {
        delete root;
    }

    vector<string> input(char inputChar)
    {
        vector<string> allSearchResults;
        if (inputChar == '#')
        {
            root->insert(root, currentString);
            freq[currentString]++;
            currentString = "";
        }
        else
        {
            currentString += inputChar;
            allSearchResults = root->search(root, currentString);
        }
        priority_queue<pis, vector<pis>, comparator> pq;
        for (auto a : allSearchResults)
        {
            if (pq.size() == 3)
            {
                if (pq.top().first < freq[a])
                {
                    pq.pop();
                    pq.push({freq[a], a});
                }
                else if (pq.top().first == freq[a])
                {
                    if (pq.top().second > a)
                    {
                        pq.pop();
                        pq.push({freq[a], a});
                    }
                }
            }
            else
            {
                pq.push({freq[a], a});
            }
        }
        vector<string> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    vector<string> sentences = {"i love you", "island", "iroman", "i love leetcode"};
    vector<int> times = {5, 3, 2, 2};
    AutocompleteSystem obj(sentences, times);
    vector<string> param_0 = obj.input('i');
    vector<string> param_1 = obj.input(' ');
    vector<string> param_2 = obj.input('a');
    vector<string> param_3 = obj.input('#');
    vector<string> param_4 = obj.input('i');
    vector<string> param_5 = obj.input(' ');
    vector<string> param_6 = obj.input('a');
    for (const auto &result : param_6)
    {
        cout << result << endl;
    }
    return 0;
}