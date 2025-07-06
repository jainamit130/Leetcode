class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        deque<pair<int,int>> dq;
        int n = nums.size();
        int j = n-1;
        int i= j;
        long long operations = 0;
        while(i>=0) {
            int newElement = nums[i];
            int popCount = 0;
            while(!dq.empty() && dq.front().first<=newElement) {
                operations+=(newElement-dq.front().first)*1LL*dq.front().second;
                popCount+=dq.front().second;
                dq.pop_front();
            }
            dq.push_front({newElement,popCount+1});
            if(operations<=k) {
                ans+=1LL*(j-i+1);
            } else {
                while(i<j && operations>k) {
                    auto [element,count] = dq.back();
                    operations-=max(0,(element-nums[j]));
                    dq.pop_back();
                    if(count-1>0)
                        dq.push_back({element,count-1});
                    j--;
                }
                ans+=1LL*(j-i+1);
            }
            i--;
        }
        return ans;
    }
};


/*
Things to do:

move left pointer -:
    if(top element val <= new element val)
        pop:  increment score by (new element val - top element val) * count 
    push: {element val, no of pop count + 1}
    increment ans by the window size

move right pointer -:
    reduce score by (new element val - element) * count 


6   3   1   2   4   4
i   j

ans = 15 + 2 = 17
operations: 3
Deque: 6,2


22  7   9   24
i       j

ans = 6
operations = 28
stack: 22,3  24,1 


20  16  15  12
        ij

ans = 1
operations = 3
stack: 15,2 


10  5   12  20  16
i           j

ans = 10
operations = 9
stack: 10,2  12,1  20,2

19  1   13  23  17
i           j

ans = 10
operations = 24
stack: 19,3 
*/