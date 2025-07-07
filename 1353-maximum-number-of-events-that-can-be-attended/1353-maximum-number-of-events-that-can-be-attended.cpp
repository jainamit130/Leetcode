class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),[](auto& lhs,auto& rhs) {
            if(lhs[0]==rhs[0]) return lhs[1]<rhs[1];
            return lhs[0]<rhs[0];
        });

        priority_queue<int,vector<int>,greater<int>> pq;
        int day = 1;
        int index = 0;
        int ans = 0;
        while(!pq.empty() || index<events.size()) {
            // remove all stale days from pq
            while(!pq.empty() && pq.top()<day) pq.pop();
            // process valid events
            while(index<events.size() && events[index][0]<=day && day<=events[index][1]) {
                pq.push(events[index][1]);
                index++;
            } 
            // if pq has some event increase and and pop 1 event
            if(!pq.empty()) {
                ans++; pq.pop();
            }
            day++;
        }
        return ans;
    }
};

/*


1   2   
1   2   
1   5  
1   5    
3   3   i   

1   2   3   4   5
1   2   3   2   2       
            j
pq =>  
currEvents = 0
ans = 2

Steps

1. sort the events both index ascending
2. go day by day
3. set up a priority queue (min heap) which will contain the end days of every event processed till now
4. for every day first remove all end days which is stale at this point
5. then cover all events ahead which falls within the current day as we go ahead put end days in pq
6. increase ans by 1 for that day if pq has some events and pop one from the pq
7. repeat until pq is empty and the events array is exhausted

*/