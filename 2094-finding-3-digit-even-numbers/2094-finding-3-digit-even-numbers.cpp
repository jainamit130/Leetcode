class Solution {
public:
    vector<int> ans;
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int> mp;

        // O(n)
        for(auto digit:digits) {
            mp[digit]++;
        }

        // O(10)
        for(int i=1;i<=9;i++) {
            if(mp.find(i)!=mp.end()) {
                mp[i]--;
                if(mp[i]==0) mp.erase(i);
                solve(mp,i);
                mp[i]++;
            }
        }
        return ans;
    }

    void solve(unordered_map<int,int>& mp,int num) {
        if(num>99) {
            ans.push_back(num); 
            return;
        }
        int digit = 0;
        int inc = num>9.length()==2 ? 2 : 1; 
        while(digit<10) {
            if(mp.find(digit)!=mp.end()) {
                mp[digit]--;
                if(mp[digit]==0) mp.erase(digit);
                solve(mp,num*10+digit);
                mp[digit]++;
            }
            digit+=inc;
        }
        return;
    }
};