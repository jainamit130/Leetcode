class Solution {
public:
    int numberOfSpecialChars(std::string word) {
        int count = 0;
        unordered_map<char,vector<int>> lowercase;
        unordered_map<char, int> uppercase;

        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (islower(ch)) {
                lowercase[ch].push_back(i);
            } else if (isupper(ch) && uppercase.find(ch) == uppercase.end()) {
                uppercase[ch] = i;
            }
        }

//         for (auto [ch, indexes] : lowercase) {
//             cout<<ch<<" => ";
//             for(auto i:indexes){
//                 cout<<i<<" ";
//             }
//             cout<<endl;
//         }
        
//         for (auto [ch,i]: uppercase) {
//             cout<<ch<<" => ";
//                 cout<<i<<" ";
//             cout<<endl;
//         }
        
        for (auto [ch, indexes] : lowercase) {
            char c=toupper(ch);
            if (uppercase.find(c) != uppercase.end()) {
                int flag=0;
                for (auto i : indexes) {
                    if (i > uppercase[c]) {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    count++;
            }
        }

        return count;
    }
};
