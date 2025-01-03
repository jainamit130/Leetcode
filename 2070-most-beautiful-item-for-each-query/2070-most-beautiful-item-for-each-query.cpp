class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int maxi = 0;
        for(auto& item:items) {
            maxi = max(maxi,item[1]);
            item[1] = maxi;
        }
        vector<int> ans;
        for(auto query:queries) {
            int start = 0;
            int end = items.size()-1;
            int subAns = 0;
            while(start<=end) {
                int mid = (start+end)/2;
                if(items[mid][0]<=query) {
                    subAns = items[mid][1];
                    start=mid+1;
                } else {
                    end=mid-1;
                }
            }
            ans.push_back(subAns);
        }
        return ans;
    }
};

/*

193 732
781 962
864 962

*/