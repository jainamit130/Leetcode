class Solution {
public:
    vector<vector<int>> cache;
    int longestSubsequence(string s, int k) {
        int leadingZeros = 0;
        int ans = 0;
        int power = log2(k);
        cache.resize(s.length()+1,vector<int>(power+1,-1));
        for(int i=0;i<s.length();i++) {
            if(s[i]=='0') {
                leadingZeros++;
            } else {
                int len = s.length()-i;
                int subAns = (power+1>len)?len:solve(s,i,power,k,power,min(power+1,len));
                ans = max(ans,leadingZeros+subAns);
            }
        }
        return max(ans,leadingZeros);
    }

    int solve(string& s,int i,int currPower,int k,int power,int len) {
        if(currPower<0) return len;
        if(i>=s.length()) return INT_MIN;
        if(s[i]=='0' && ((k>>currPower)&1)==1) return ((s.length()-i)>=currPower)?len:INT_MIN;
        if(cache[i][currPower]!=-1) return cache[i][currPower];
        if((s[i]=='1' && ((k>>currPower)&1)==1) || (s[i]=='0' && ((k>>currPower)&1)==0)) return cache[i][currPower] = solve(s,i+1,currPower-1,k,power,len);
        if(s[i]=='0' && ((k>>currPower)&1)==1)) 
        return cache[i][currPower] = solve(s,i+1,currPower,k,power,len);
    }
};



/*


0   0   



*/