class Solution {
public:
    int numTilePossibilities(string tiles) {
        int ans = 0;
        unordered_map<char,int> freq;
        for(auto ch:tiles) {
            freq[ch]++;
        }
        for(int i=1;i<=tiles.size();i++) {
            unordered_set<string> generated;
            int subAns = solve(i,"",generated,freq);
            ans += subAns;
        }
        return ans;
    }

    int solve(int size,string subAns,unordered_set<string>& generated,unordered_map<char,int>& freq) {
        if(subAns.length()==size) {
            if(generated.find(subAns)==generated.end()) {
                generated.insert(subAns);
                return 1;
            }
            return 0;
        }

        if(freq.size()==0) {
            return 0;
        }
        int ans = 0;
        unordered_map<char,int> copyMp = freq;
        for(auto [ch,count]:freq) {
            unordered_map<char,int> tempMp = freq;
            tempMp[ch]--;
            if(tempMp[ch]==0) {
                tempMp.erase(ch);
            }
            ans += solve(size,subAns+ch,generated,tempMp);
        }
        freq = copyMp;
        return ans;
    }
};

/*

A   A   B   

_ => 2
_ _ => 3
_ _ _ => 3


*/