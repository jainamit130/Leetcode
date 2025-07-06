class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        long long sum=0;
        using pii=pair<int,int>;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(int i=nums.size()-1;i>=0;i--){
            pq.push({nums[i],i});
            sum+=nums[i];
        }
        unordered_set<int> marked;
        vector<long long> ans;
        for(auto q:queries){
            int index=q[0];
            int k=q[1];
            if(marked.find(index)==marked.end()){
                marked.insert(index);
                sum-=nums[index];
            }
            while(!pq.empty() && sum>0 && k){
                int ind=pq.top().second;
                pq.pop();
                if(marked.find(ind)!=marked.end()){
                    continue;
                } 
                sum-=nums[ind];
                marked.insert(ind);
                k--;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};