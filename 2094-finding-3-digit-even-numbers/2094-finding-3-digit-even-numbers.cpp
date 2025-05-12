class Solution {
public:
    vector<int> ans;
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int> mp;
        for(auto digit:digits) {
            mp[digit]++;
        }
        for(int i=0;i<=8;i+=2) {
            if(mp.find(i)!=mp.end()) {
                mp[i]--;
                if(mp[i]==0) mp.erase(i);
                solve(mp,string(1,char(i+'0')));
                mp[i]++;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }

    void solve(unordered_map<int,int>& mp,string numStr) {
        if(numStr.length()==3) {
            ans.push_back(stoi(numStr)); 
            return;
        }
        int digit = numStr.length()==2 ? 1 : 0;
        while(digit<10) {
            if(mp.find(digit)!=mp.end()) {
                mp[digit]--;
                if(mp[digit]==0) mp.erase(digit);
                solve(mp,string(1, char(digit + '0'))+numStr);
                mp[digit]++;
            }
            digit++;
        }
        return;
    }
};