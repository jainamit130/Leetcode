class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int,int>> maxHeap;
        for(int i=0;i<profit.size();i++){
            maxHeap.push({profit[i],difficulty[i]});
        }
        int ans=0;
        sort(worker.begin(),worker.end());
        int i=worker.size()-1;
        while(i>=0 && !maxHeap.empty()){
            while(!maxHeap.empty() && maxHeap.top().second>worker[i]){
                maxHeap.pop();
            }
            if(!maxHeap.empty()){
                ans+=maxHeap.top().first;
                i--;
            }
        }
        return ans;
    }
};



/*

difficulty = 2   4   6   8   10
profit =     10  20  30  40  50
worker =     4   5   6   7



*/