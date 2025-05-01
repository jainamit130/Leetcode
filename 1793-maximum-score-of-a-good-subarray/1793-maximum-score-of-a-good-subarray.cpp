class Solution {
public:
    int n;
    int maximumScore(vector<int>& nums, int k) {
        n = nums.size();
        vector<int> nextSmaller(n);
        populateMinElements(nextSmaller,nums,1);
        vector<int> prevSmaller(n);
        populateMinElements(prevSmaller,nums,0);

        int ans = 0;
        for(int i=0;i<n;i++) {
            int start = prevSmaller[i];
            int end = nextSmaller[i];
            if(start<k && end>k) ans = max((end-start-1)*nums[i],ans);
        }
        return ans;
    }

    void populateMinElements(vector<int>& arr,vector<int>& nums,int isNextSmaller) {
        int index = isNextSmaller?n-1:0;
        int inc = isNextSmaller?-1:1;
        int count = n;
        stack<pair<int,int>> st;
        if(isNextSmaller) st.push({-1,n});
        else st.push({-1,-1});
        while(count) {
            int i = index;
            while(!st.empty() && st.top().first>=nums[i]) st.pop();
            i = st.top().second;
            arr[index]=i;
            st.push({nums[index],index});
            index+=inc;
            count--;
        }
        return;
    }
    
};

// class Solution {
// public:
//     int maximumScore(vector<int>& nums, int k) {
//         int ans = getMaxScore(nums,k);
//         reverse(nums.begin(),nums.end());
//         return max(ans,getMaxScore(nums,nums.size()-k-1));
//     }

//     int getMaxScore(vector<int>& nums,int k) {
//         vector<int> left;
//         int mini = INT_MAX;
//         for(int i=k-1;i>=0;i--) {
//             mini = min(nums[i],mini);
//             left.push_back(mini);
//         }
//         reverse(left.begin(),left.end());
//         int ans = 0;
//         mini = INT_MAX;
//         for(int i=k;i<nums.size();i++) {
//             mini = min(mini,nums[i]);    
//             int index = upper_bound(left.begin(),left.end(),mini-1)-left.begin();
//             ans = max(ans,abs(i-index+1)*mini);
//         }
//         return ans;
//     }
// };


/*

1. create a left array 
2. store the running min in it from the k-1 to 0 index
3. the left will be naturally sorted 
3. consider starting from the index k as the min element
3. binary search for the upper bound value of the considered min element + 1
4. keep maximizing the score until the right array is exhausted
5. reverse the array and then do the exact same thing 

0   1   2   3   4   5   6   7   8   9   10
2   2   2   2   5   5   6   6   8   8   8   

upper bound of 4


*/