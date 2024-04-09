class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        for(int i=0;i<tickets.size();i++)
            q.push({tickets[i],i});
        int time=0;
        while(1){
            int t=q.front().first;
            int ti=q.front().second;
            if(t>1){
                q.pop();
                time++;
                q.push({t-1,ti});
            } else if(t==1 && ti==k)
                return ++time;
            else {
                q.pop();
                time++;
            }
        }
        return time;
    }
};



/*


2   3   2
i


*/