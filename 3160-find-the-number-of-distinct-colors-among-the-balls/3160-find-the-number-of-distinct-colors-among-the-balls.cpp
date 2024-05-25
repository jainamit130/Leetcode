class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> mp;
        unordered_map<int,int> colors;
        vector<int> ans;
        for(auto q:queries){
            if(mp.find(q[0])!=mp.end(q[0])){
                int oldColor = mp[q[0]];
                colors[oldColor]--;
                if(colors[oldColor]==0)
                    colors.erase(oldColor);
            } 
            colors[q[1]]++;
            mp[q[0]]=q[1];
            ans.push_back(colors.size());
        }
        return ans;
    }
};