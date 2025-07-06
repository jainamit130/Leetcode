class Solution {
public:
    int candy(vector<int>& ratings) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minHeap;
        for(int i=0;i<ratings.size();i++){
            minHeap.push({ratings[i],i});
        }
        vector<int> rate(ratings.size(),INT_MAX);
        int ans=0;
        while(!minHeap.empty()){
            int index=minHeap.top()[1];
            int val=1;
            if(index>0){
                if(minHeap.top()[0]>ratings[index-1]){
                    val=rate[index-1]+1;
                }
            }
            if(index<rate.size()-1){
                if(minHeap.top()[0]>ratings[index+1]){
                    val=max(rate[index+1]+1,val);
                }
            }
            ans+=val;
            minHeap.pop();
            rate[index]=val;
        }
        return ans;
    }
};

/*

1   0   2
m   m   m
m   1   m
2   1   m
2   1   2


1   2   3   4   5   5   0   3   2   1

m   m   m   m   m   m   1   m   m   m
1   m   m   m   m   m   1   m   m   1
1   2   m   m   m   m   1   m   2   1
1   2   3   m   m   m   1   3   2   1
1   2   3   4   m   m   1   3   2   1
1   2   3   4   5   2   1   3   2   1

*/