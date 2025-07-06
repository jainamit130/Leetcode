class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degrees(n+1);
        map<pair<int,int>,int> edgesFreq;
        for(auto edge:edges) {
            degrees[edge[0]]++;
            degrees[edge[1]]++;
            edgesFreq[{min(edge[0],edge[1]),max(edge[0],edge[1])}]++;
        }

        vector<int> sortedDegrees = degrees;
        sort(sortedDegrees.begin(),sortedDegrees.end());
        vector<int> ans;
        for(auto q:queries) {
            int subAns = 0;
            int start = 1;
            int end = n;
            while(start<end) {
                if(sortedDegrees[start]+sortedDegrees[end]>q) {
                    subAns += (end-start);
                    end--;
                } else start++;
            }

            for(auto& [edge,count]: edgesFreq) {
                if(degrees[edge.first]+degrees[edge.second]>q && degrees[edge.first]+degrees[edge.second]-count<=q) {
                    subAns--;
                }
            }
            ans.push_back(subAns);
        }
        return ans;
    }
};