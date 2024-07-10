class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(),changed.end());
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<changed.size();i++){
            if(changed[i]%2==0 && mp.find(changed[i]/2)!=mp.end()){
                mp[changed[i]/2]--;
                if(mp[changed[i]/2]==0){
                    mp.erase(changed[i]/2);
                }
                ans.push_back(changed[i]/2);
            } else {
                mp[changed[i]]++;
            }
        }
        if(mp.size()>0){
            return {};
        }
        return ans;
    }
};


/*


1   2   3   4   6   8
            i

o: 1    3   

d: 2


*/