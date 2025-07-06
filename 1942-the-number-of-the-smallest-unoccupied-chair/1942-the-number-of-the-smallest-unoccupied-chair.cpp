#define PII pair<int,int>
class Solution {
public:
    static bool sortcol(vector<int>& v1,vector<int>& v2){
        return v1[0]<v2[0];
    }
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n=times.size();
        priority_queue<PII , vector<PII> , greater<PII>> occupied;
        priority_queue<int,vector<int>,greater<int> > vacant;

        for(int i=0;i<n;i++){
            vacant.push(i);
        }
        int target=times[targetFriend][0];
        sort(times.begin(),times.end(),sortcol);
        cout<<endl;

        for(auto i:times){
            int start=i[0];
            int end=i[1];
            while(!occupied.empty() && start>=occupied.top().first){
                vacant.push(occupied.top().second);
                occupied.pop();
            }
            if(start==target){
                return vacant.top();
            }
            occupied.push({end,vacant.top()});
            vacant.pop();
        }

        return -1;
    }
};