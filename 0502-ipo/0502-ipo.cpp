class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        for(int i=0;i<capital.size() && k>0;i++){
            if(capital[i]<=w){
                pq.push(profits[i]);
            } else {
                while(!pq.empty() && capital[i]>w && k>0){
                    w+=pq.top();
                    k--;
                    pq.pop();
                }
                if(capital[i]<=w){
                    pq.push(profits[i]);
                }
            }
        }
        while(!pq.empty() && k>0){
            w+=pq.top();
            k--;
            pq.pop();
        }
        return w;
    }
};

/*

k = 2, 
w = 0,  
profits = [1,2,3], 
capital = [0,1,1]


0   1   1
1   3   2


*/