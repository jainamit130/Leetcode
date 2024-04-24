class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        unordered_map<int,vector<int>> indexes;
        stack<int> st;
        int ans=0;
        vector<int> prevGreater(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(!st.empty())
                prevGreater[i]=st.top();
            st.push(i);
        }

        // for(int i=0;i<nums.size();i++){
        //     cout<<prevGreater[i]<<endl;
        // }

        for(int i=0;i<nums.size();i++){
            indexes[nums[i]].push_back(i);
            ans+=indexes[nums[i]].end()-upper_bound(indexes[nums[i]].begin(),indexes[nums[i]].end(),prevGreater[i]);
        }
        return ans;
    }
};



/*


1   4   3   3   2
0   1   2   3   4
1   4   4   4   3
0   1   

ans = 1 + 1 + 

stack: 4    3

Map:
1 -> 0
4 -> 1
3 -> 2



*/