class StockSpanner {
public: 
    stack<pair<int,int>> st;
    StockSpanner() {
    }
    
    int next(int price) {
        int span = 0;
        while(!st.empty() && price>st.top().first) {
            span += st.top().second;
            st.pop();    
        }
        span++;
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */