class StockPrice {
public:
    using pii = pair<int,int>;
    priority_queue<pii,vector<pii>,greater<pii>> minHeap;
    priority_queue<pii> maxHeap;
    map<int,int> timestampToVal;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        timestampToVal[timestamp]=price;
        minHeap.push( {price,timestamp} );
        maxHeap.push( {price,timestamp} );
    }
   
    int current() {
        auto itr = timestampToVal.end();
        itr--;
        return itr->second;
    }
    
    int maximum() {
        while(!maxHeap.empty() && timestampToVal[maxHeap.top().second]!=maxHeap.top().first) {
            maxHeap.pop();
        }
        return maxHeap.top().first;
    }
    
    int minimum() {
        while(!minHeap.empty() && timestampToVal[minHeap.top().second]!=minHeap.top().first) {
            minHeap.pop();
        }
        return minHeap.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */