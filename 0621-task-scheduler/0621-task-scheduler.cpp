class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26);
        for(int i=0;i<tasks.size();i++)
            mp[tasks[i]-'A']++;
        priority_queue<int> pq;
        queue<vector<int>> q;
        for(int i=0;i<26;i++){
            if(mp[i]!=0){
                pq.push(mp[i]);
            }
        }
        int time=0;
        while(!pq.empty() or !q.empty()){
            time++;
            if(!pq.empty()){
                int freq=pq.top()-1;
                pq.pop();
                if(freq!=0)
                    q.push({freq,time+n});
            }
            while(!q.empty() && q.front()[1]==time){
                pq.push(q.front()[0]);
                q.pop();
            }
        }
        return time;
    }
};