bool myCmp(vector<int>& a,vector<int>& b) {
    return a[0] < b[0];
}

class Solution {
public:
    typedef pair<long, int> P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), myCmp);
        long time = 0;
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; i++)
            freeRooms.push(i);
        priority_queue<P, vector<P>, greater<P>> endTimesOfOccupiedRooms;
        map<int, int> mp;
        int i = 0;
        while (i < meetings.size()) {
            // print(freeRooms,endTimesOfOccupiedRooms,mp,time,n,i,meetings);
            while (!endTimesOfOccupiedRooms.empty() &&
                   time == endTimesOfOccupiedRooms.top().first) {
                freeRooms.push(endTimesOfOccupiedRooms.top().second);
                endTimesOfOccupiedRooms.pop();
            }
            while(i<meetings.size() && meetings[i][0]<=time && !freeRooms.empty()){
                P upcomingMeet = {meetings[i][0], meetings[i][1]};
                int duration = upcomingMeet.second - upcomingMeet.first;
                if (time >= upcomingMeet.first) {
                    if (!freeRooms.empty()) {
                        int freeRoom = freeRooms.top();
                        freeRooms.pop();
                        mp[freeRoom]++;
                        endTimesOfOccupiedRooms.push({duration + time, freeRoom});
                        i++;
                    }
                }
            }
            if(!endTimesOfOccupiedRooms.empty() && freeRooms.empty())
                time=endTimesOfOccupiedRooms.top().first;
            else
                time++;
        }
        // print(freeRooms,endTimesOfOccupiedRooms,mp,time,n,i,meetings);
        int maxi = 0;
        int ans = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (maxi <= mp[i]) {
                maxi = mp[i];
                ans = i;
            }
        }
        return ans;
    }

    void print(priority_queue<int, vector<int>, greater<int>> freeRooms,priority_queue<P, vector<P>, greater<P>> endTimesOfOccupiedRooms,map<int, int> mp,int time,int n,int i,vector<vector<int>> meetings){
        cout<<"time = "<< time<<endl;
        if(i<meetings.size())
            cout<<"Upcoming Meet : "<<meetings[i][0]<<","<<meetings[i][1]<<endl;
        else 
            cout<<"All meetings over"<<endl;
        cout<<"FreeRooms: ";
        while(!freeRooms.empty()){
            cout<<freeRooms.top()<<",";
            freeRooms.pop();
        }
        cout<<endl<<"End Time with Occupied Rooms: "<<endl;
        while(!endTimesOfOccupiedRooms.empty()){
            cout<<endTimesOfOccupiedRooms.top().first<<","<<endTimesOfOccupiedRooms.top().second<<endl;
            endTimesOfOccupiedRooms.pop();
        }
        cout<<"Map"<<endl;
        for(int i=0;i<n;i++){
            cout<<i<<"->"<<mp[i]<<endl;
        }
        cout<<endl;
    }
};