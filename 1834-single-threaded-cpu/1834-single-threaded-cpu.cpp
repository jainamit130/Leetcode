struct comparator {
    bool operator()(auto lhs,auto rhs){
        if(rhs[0]==lhs[0]){
            return lhs[1]>rhs[1];
        } 
        return lhs[0]>rhs[0];
    }
};


class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& t) {
        vector<vector<int>> tasks;
        for(int i=0;i<t.size();i++){
            tasks.push_back({t[i][0],t[i][1],i});
        }
        sort(tasks.begin(),tasks.end());
        priority_queue<vector<int>,vector<vector<int>>,comparator> pq;
        int i=0;
        int time=0;
        vector<int> ans;
        while(i<tasks.size()){
            if(pq.empty())
                time=max(tasks[i][0],time);
            while(i<tasks.size() && time>=tasks[i][0]){
                pq.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            if(!pq.empty()){
                time+=pq.top()[0];
                ans.push_back(pq.top()[1]);
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top()[1]);
            pq.pop();
        }
        return ans;
    }
};



/*

1   2   0
2   4   1
3   2   2
4   1   3


1   2



*/