class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> corners;
        for(auto b:buildings){
            corners.push_back({b[0],b[2]});
            corners.push_back({b[1],-b[2]});
        }
        sort(corners.begin(),corners.end(),[](auto lhs,auto rhs){
            if(lhs[0]==rhs[0]){
                return lhs[1]>rhs[1];
            }
            return lhs[0]<rhs[0];
        });
        vector<vector<int>> ans;
        multiset<int> pq;
        pq.insert(0);
        int currH=0;
        for(auto c:corners){
            if(c[1]>0){
                pq.insert(c[1]);
            } else {
                auto it = pq.find(-c[1]); 
                if (it != pq.end()) {
                    pq.erase(it); 
                }
            }
            if(currH != *pq.rbegin()){
                ans.push_back({c[0],*pq.rbegin()});
                currH = *pq.rbegin();
            }
        }
        return ans;
    }
};


/*

2   10
3   15
5   12
7   15
9   10
12  12


15  10
19  8
20  10
24  8



*/