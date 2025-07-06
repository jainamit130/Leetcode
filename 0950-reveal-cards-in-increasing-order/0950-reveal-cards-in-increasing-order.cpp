// #Approach 1
// class Solution {
// public:
//     vector<int> deckRevealedIncreasing(vector<int>& deck) {
//         deque<int> q;
//         sort(deck.begin(),deck.end(),[](auto lhs,auto rhs){
//             return lhs>rhs;
//         });
//         vector<int> ans;
//         for(auto d:deck){
//             lastToFirst(q);
//             q.push_front(d);
//         }   
//         while(!q.empty()){
//             ans.push_back(q.front());
//             q.pop_front();
//         }
//         return ans;
//     }

//     void lastToFirst(deque<int>& q){
//         if(q.empty() || q.size()==1)
//             return;
//         int temp=q.back();
//         q.pop_back();
//         q.push_front(temp);
//         return;
//     }
// };


// #Approach 2
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        for(int i=0;i<deck.size();i++)
            q.push(i);
        sort(deck.begin(),deck.end());
        vector<int> ans(deck.size());
        for(auto d:deck){
            int index=q.front();
            q.pop();
            ans[index]=d;
            int skip=q.front();
            q.pop();
            q.push(skip);
        }
        return ans;
    }
};



/*

2   3   5   7   11  13  17  19  20  22  23  24  25

2       3       5       7       11      13      17

17,13,11,2,3,5,7,19,20,22,23,24,25

2   3    5   7   11  13  17 

2       3       5       7

*/