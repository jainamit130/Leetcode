class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> freq;
        unordered_set<int> st;
        unordered_map<int,pair<int,int>> freqFreq;
        for(auto n:nums) freq[n]++;
        for(auto [n,f]:freq) freqFreq[f]={freqFreq[f].first+1,n};
        int ans = -1;
        for(auto [ff,fn]:freqFreq) if(fn.first==1) st.insert(fn.second);
        for(auto n:nums) if(st.find(n)!=st.end()) return n;
        return ans;
    }
};