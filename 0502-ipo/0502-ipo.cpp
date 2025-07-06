class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>> capitalPro(capital.size());
        for(int i=0;i<capital.size();i++){
            capitalPro[i]={capital[i],profits[i]};
        }
        sort(capitalPro.begin(),capitalPro.end());
        priority_queue<int> pq;
        for(int i=0;i<capitalPro.size() && k>0;i++){
            if(capitalPro[i][0]<=w){
                pq.push(capitalPro[i][1]);
            } else {
                while(!pq.empty() && capitalPro[i][0]>w && k>0){
                    w+=pq.top();
                    k--;
                    pq.pop();
                }
                if(capitalPro[i][0]<=w){
                    pq.push(capitalPro[i][1]);
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