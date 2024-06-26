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
        map<int,int> pq;
        pq[0]=1;
        int currH=0;
        for(auto c:corners){
            if(c[1]>0){
                pq[c[1]]++;
            } else {
                pq[-c[1]]--;
                if(pq[-c[1]]==0)
                    pq.erase(-c[1]);
            }
            if(currH != pq.rbegin()->first){
                ans.push_back({c[0],pq.rbegin()->first});
                currH = pq.rbegin()->first;
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