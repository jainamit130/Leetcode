class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans = 0;
        for(auto n:st) {
            if(st.find(n-1)==st.end()) {
                int nextNum = n+1;
                int subAns = 1;
                while(st.find(nextNum)!=st.end()) {
                    subAns++;
                    nextNum++;
                }
                ans = max(subAns,ans);
            }
        }
        return ans;
    }   
};

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_map<int,int> startToEnd;
//         unordered_map<int,int> endToStart;
//         unordered_set<int> st;
//         int ans = 0;
//         for(auto n:nums) {
//             if(st.find(n)!=st.end()) continue;
//             int nextNum = n+1;
//             int prevNum = n-1;
//             if(startToEnd.find(nextNum)!=startToEnd.end() && endToStart.find(prevNum)!=endToStart.end()) {
//                 int start = endToStart[prevNum];
//                 int end = startToEnd[nextNum];
//                 endToStart.erase(prevNum);
//                 endToStart[end]=start;
//                 startToEnd[start]=end;
//                 ans = max(ans,end-start+1);
//             } else if(startToEnd.find(nextNum)!=startToEnd.end()) {
//                 int end = startToEnd[nextNum];
//                 endToStart[end] = n;
//                 startToEnd[n] = end;
//                 startToEnd.erase(nextNum);
//                 ans = max(ans,end-n+1);  
//             } else if(endToStart.find(prevNum)!=endToStart.end()) {
//                 int start = endToStart[prevNum];
//                 startToEnd[start] = n;
//                 endToStart[n] = start;
//                 endToStart.erase(prevNum);
//                 ans = max(ans,n-start+1);  
//             } else {
//                 startToEnd[n]=n;
//                 endToStart[n]=n;
//                 ans = max(ans,1);
//             }
//             st.insert(n);
//         }
//         return ans;
//     }   

// };


/*

97  100 102 105 101 104 98  103 99

97          100         102         105                  


End
105 -> 97

Start
97 -> 105


97  100 102 105 101 104 98  103 99
                                i


100     4       200     1       3       2
                                i

start
100 -> 100
200 -> 200
4 -> 4
1 -> 1

end
200 -> 200
100 -> 100
4 -> 3
1 -> 1

Approach:
1. initialize a end and start map 
2. iterate over nums
3. check if both nums-1 and nums+1 exists in end and start respectively 
    i. if yes then update both start and end map with new key->value
4. check if nums-1 exist in end 
    i. if exists then get the start and update the start map with new end and update back the end map by deleting the old end->start with new end->start
5. check if nums+1 exists in start
    i. if exists then get the end and update the end map with new start and update back the start map by deleting the old start->end with new start->end



Clarifying questions => 
1. nums array is going to contain only integers? +ve only ? you can assume that
2. can there be duplicates? yes
3. do i need to return what? max length
4. can nums array be empty? yes in that case return 0

Ex:

100  5  3   200 90  57  63  78
                    3   2   1

max = 3
num = 57

100 -> 200
5 -> 57 -> 63 -> 78


*/