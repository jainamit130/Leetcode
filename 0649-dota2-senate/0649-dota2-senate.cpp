class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r;
        queue<int> d;
        int n=senate.size();
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R')
                r.push(i);
            else
                d.push(i);
        }
        while(!r.empty() && !d.empty()){
            if(r.front()<d.front()){
                int t=r.front();
                r.pop();
                r.push(t+n);
                d.pop();
            } else {
                int t=d.front();
                d.pop();
                d.push(t+n);
                r.pop();
            }
        }
        if(r.empty())
            return "Dire";
        return "Radiant";
    }
};