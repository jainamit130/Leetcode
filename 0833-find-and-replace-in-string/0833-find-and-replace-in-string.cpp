class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int k = sources.size();
        int n = s.length();
        vector<int> indexes(k);
        iota(indexes.begin(),indexes.end(),0);
        sort(indexes.begin(),indexes.end(),[&](auto lhs,auto rhs) {
            return indices[lhs]<indices[rhs];
        });

        string ans = "";
        int i = 0;
        int sIndex = 0;
        while(sIndex<n) {
            if(i<k) {
                int index = indexes[i];
                int indicesIndex = indices[index];
                if(indicesIndex == sIndex) {
                    string source = sources[index];
                    if(source.length()<=n-sIndex && s.substr(sIndex,source.length())==source) {
                        ans += targets[index];
                        sIndex += source.length();
                        i++;
                    } else { 
                        i++;
                    }
                    continue;
                }
            }
            ans += s[sIndex];
            sIndex++;
        }
        return ans;
    }
};

// class Solution {
// public:
//     string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
//         unordered_map<int,pair<string,int>> changeMap;
//         for(int i=0;i<indices.size();i++) {
//             int index = indices[i];
//             string source = sources[i];
//             if(source.length()<=s.length()-index && s.substr(index,(int)source.length())==source) {
//                 changeMap[index]={targets[i],source.length()};
//             }
//         }

//         string ans = "";
//         int i = 0;
//         while(i<s.length()) {
//             if(changeMap.find(i)!=changeMap.end()) {
//                 ans += changeMap[i].first;
//                 i += changeMap[i].second;
//             } else {
//                 ans += s[i];
//                 i++;
//             }
//         }
//         return ans;
//     }
// };


/*
0   1   2   3   4   5
a   b   c   d   e   f   g   h
        j   k   l   m
2
cde

Given

string => s - all small case english alphabets? yes, can it be empty? no
all 3 below of length k => >0
indices => vector<int> => size k => always within <s.length()
sources => vector<string> => size k
targets => vector<string> => size k

Ex:
0   1   2   3   4   5   6   7   8   9
a   b   d   h   g   y   c   b   d   a

[3,0,8]
["hgy","abh","da"]
["g","sdz","xyz"]


Approach:

1. string ans = "" 
2. iterate the indices array with it get the substring from sources => check if sources[indices[i]]==s.substr(s.begin()+indices[i],sources[indices[i]].length()) if yes then add it to changeMap (index->new substring) mapping
O(k) time and O(k*max(target[i].length()))
3. basically now iterate the original string and form ans O(n) time and O(max(n,k*max(target[i].length()))) space

Time

O(n+k)
O(n + k*max(target[i].length()))


*/