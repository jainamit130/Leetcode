class Solution {
public:
    vector<vector<int>> cases={{0,3},{1,2},{2,1},{3,0}};
    int minDifference(vector<int>& nums) {
        priority_queue<int> maxHeap; 
        priority_queue<int,vector<int>,greater<int>> minHeap; 

        for(auto n:nums){
            if(maxHeap.size()<=3){
                maxHeap.push(n);
            } else {
                if(maxHeap.top()>n){
                    maxHeap.pop();
                    maxHeap.push(n);
                }
            }

            if(minHeap.size()<=3){
                minHeap.push(n);
            } else {
                if(minHeap.top()<n){
                    minHeap.pop();
                    minHeap.push(n);
                }
            }
        }

        priority_queue<int> newMaxHeap; 
        priority_queue<int,vector<int>,greater<int>> newMinHeap; 

        //minHeap to new maxHeap
        while(!minHeap.empty()){
            newMaxHeap.push(minHeap.top());
            minHeap.pop();
        }

        //maxHeap to new minHeap
        while(!maxHeap.empty()){
            newMinHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        int ans=INT_MAX;
        for(auto n:cases){
            ans=min(ans,solve(newMinHeap,newMaxHeap,n[0],n[1]));
        }
        return ans;
    }

    int solve(priority_queue<int,vector<int>,greater<int>> minHeap,priority_queue<int> maxHeap,int a,int b){
        while(a){
            minHeap.pop();
            a--;
        }
        while(b){
            maxHeap.pop();
            b--;
        }
        return abs(minHeap.top()-maxHeap.top());
    }
};