// # Approach 1
// class Solution {
// public:
//     int timeRequiredToBuy(vector<int>& tickets, int k) {
//         queue<pair<int,int>> q;
//         for(int i=0;i<tickets.size();i++)
//             q.push({tickets[i],i});
//         int time=0;
//         while(1){
//             int t=q.front().first;
//             int ti=q.front().second;
//             if(t>1){
//                 q.pop();
//                 time++;
//                 q.push({t-1,ti});
//             } else if(t==1 && ti==k)
//                 return ++time;
//             else {
//                 q.pop();
//                 time++;
//             }
//         }
//         return time;
//     }
// };


// #Approach 2
// class Solution {
//     public:
//         int timeRequiredToBuy(vector<int>& tickets, int k) {
//             int ans=0;
//             int i=0;
//             while(1){
//                 if(tickets.size()==i)
//                     i=0;
//                 if(tickets[i]>0)
//                     ans++;
//                 tickets[i]=tickets[i]-1;
//                 if(tickets[k]==0)
//                     break;
//                 i++;
//             }
//             return ans;
//         }
// };

// #Approach 3
class Solution {
    public:
        int timeRequiredToBuy(vector<int>& tickets, int k) {
            int ans=0;
            for(int i=0;i<tickets.size();i++){
                if(i>k)
                    ans+=min(tickets[i],tickets[k]-1);
                else
                    ans+=min(tickets[i],tickets[k]);
            }
            return ans;
        }
};


/*


2   3   2
i


*/