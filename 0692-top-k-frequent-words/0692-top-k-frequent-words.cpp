struct comparator{
    bool operator()(auto lhs,auto rhs){
        if(lhs.first==rhs.first){
            return lhs.second<rhs.second;
        }
        return lhs.first>rhs.first;
    }
};

class Solution {
public:
    using pii=pair<int,string>;
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        priority_queue<pii,vector<pii>,comparator> pq;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        for(auto [word,freq]: mp){
            if(pq.size()==k){
                if(pq.top().first<freq){
                    pq.pop();
                    pq.push({freq,word});
                } else if(pq.top().first==freq){
                    if(pq.top().second>word){
                        pq.pop();
                        pq.push({freq,word});
                    }
                }
            } else {
                pq.push({freq,word});
            }
        }
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};