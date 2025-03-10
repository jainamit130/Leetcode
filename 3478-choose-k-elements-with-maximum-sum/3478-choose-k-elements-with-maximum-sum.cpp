class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> n1;
        int n = nums1.size();
        for(int i=0;i<n;i++) {
            n1.push_back({nums1[i],i});
        }
        sort(n1.begin(),n1.end());
        priority_queue<int,vector<int>,greater<int>> minHeap;
        vector<long long> ans(n);
        minHeap.push(nums2[n1[0][1]]);
        long long currTotal = nums2[n1[0][1]];
        for(int i=1;i<n;i++) {
            if(n1[i-1][0]==n1[i][0]) {
                ans[n1[i][1]]=ans[n1[i-1][1]];
            } else {
                ans[n1[i][1]]=currTotal;
            }
            processHeap(minHeap,currTotal,k,nums2[n1[i][1]]);
        }
        return ans;
    }

    void processHeap(priority_queue<int,vector<int>,greater<int>>& minHeap,long long& currTotal,int k,int value) {
        minHeap.push(value);
        currTotal+=1LL*value;
        if(minHeap.size()>k) {
            currTotal-=1LL*minHeap.top();
            minHeap.pop();
        }
        return;
    }
};



/*

0   1   2   3   4   5
4   2   1   5   3   1



2   5   1   4   0   3
1   1   2   3   4   5


currTotal = 130
minheap: 30 100  

0   1   2   3   4   5
10  20  30  40  50  100




*/