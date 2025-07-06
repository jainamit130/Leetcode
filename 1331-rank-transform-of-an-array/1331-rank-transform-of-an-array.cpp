class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> ans,arrc=arr;
        sort(arrc.begin(),arrc.end());
        int rank=0;
        unordered_map<int,int> mp;
        for(auto n:arrc){
            if(mp.find(n)==mp.end()){
                rank++;
            }
            mp[n]=rank;            
        }

        for(auto n:arr){
            ans.push_back(mp[n]);
        }
        return ans;
    }
};