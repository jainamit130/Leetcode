class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        int i = nums.size()-1;
        while(i>=0) {
            // pop all invalid elements from top of stack
            while(st.top()>nums[i]) st.pop();
            // stack top if is smaller than current element then increase ans
            ans += nums[i]!=0 && st.top()<nums[i];
            st.push(nums[i]);
            i--;
        }
        return ans;
    }
};


/*

Stack: 




2   1   1   3   1   2   3   2   3   1   1   3
i
1   1   1   1   1   2   2   1   1   1   -   -   
1   0   0   1   0   0   1   1   1   0   1   1

if currVal > nextMinVal

operations: 7



2   0   0   3   0   2   3   2   3   0   0   3
opera: 1

0   0   0   3   0   0   3   0   3   0   0   3
opera: 2


0   0   0   0   0   0   0   0   0   0   0   0
opeara: 4




1   0   0   1   0   0   1   1   1   0   1   1


2   1   1   3   1   2   3   2   3   1   1   3
2   0   0   3   0   2   3   2   3   0   0   3
0   0   0   3   0   0   3   0   3   0   0   3  
0   0   0   0   0   0   0   0   0   0   0   0

*/