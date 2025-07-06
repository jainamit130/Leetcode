class Solution {
public:
    unordered_map<int,char> mp;
    string concatHex36(int n) {
        int val = 0;
        for(;val<=9;val++) mp[val]=(char)(val+'0');
        for(char ch = 'A'; ch<='Z';ch++) mp[val++]=ch;
        return getBaseNum(n*n,16) + getBaseNum(n*n*n,36);
    }

    string getBaseNum(int n,int base) {
        string ans = "";
        while(n) {
            int val = n%base;
            ans += string(1,mp[val]);
            n/=base;
        } 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


/*


169

*/