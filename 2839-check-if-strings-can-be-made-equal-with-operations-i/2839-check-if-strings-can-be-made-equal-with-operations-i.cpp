class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        unordered_map<char,int> odd,even;
        for(int i=0;i<s1.length();i++) {
            if(i%2!=0) odd[s1[i]]++;
            if(i%2==0) even[s1[i]]++;
        }

        for(int i=0;i<s2.length();i++) {
            if(i%2!=0 && odd.find(s2[i])!=odd.end()) {
                odd[s2[i]]--;
                if(odd[s2[i]]==0) odd.erase(s2[i]);
            } else if(i%2==0 && even.find(s2[i])!=even.end()) {
                even[s2[i]]--;
                if(even[s2[i]]==0) even.erase(s2[i]);
            } else return false;
        }
        return true;
    }
};


/*
0123
abcd



*/