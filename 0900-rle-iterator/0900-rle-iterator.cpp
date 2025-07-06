class RLEIterator {
public:
    deque<pair<int,int>> dq;
    RLEIterator(vector<int>& encoding) {
        for(int i=0;i<encoding.size();i+=2) {
            if(encoding[i]!=0) dq.push_back({encoding[i],encoding[i+1]});
        }
    }
    
    int next(int n) {
        int val = -1;
        while(n && !dq.empty()) {
            auto [count,value] = dq.front();
            val = value;
            dq.pop_front();
            int temp = max(n-count,0);
            count-=min(count,n);
            n = temp;
            if(count>0) dq.push_front({count,value});
        }
        return n!=0?-1:val;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */