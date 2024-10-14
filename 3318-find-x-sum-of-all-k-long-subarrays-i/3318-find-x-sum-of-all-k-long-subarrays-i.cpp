class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n=nums.size();
        for(int j=k-1;j<n;j++){
            int sum=0;
            unordered_map<int,int> freq;
            set<pair<int,int>> st;
            for(int i=j-k+1;i<=j;i++){
                sum+=nums[i];
                if(st.find( {freq[nums[i]],nums[i]} )!=st.end()){
                    st.erase({freq[nums[i]],nums[i]});
                }
                freq[nums[i]]++;
                st.insert({freq[nums[i]],nums[i]});
            }

            while(st.size()>x){
                auto [smallestFreq,smallestNum] = *st.begin();
                sum-=smallestFreq*smallestNum;
                st.erase({smallestFreq,smallestNum});
            }

            ans.push_back(sum);
        }
        return ans;
    }
};


/*

Traversing the window
track sum
track freq
set<pair<int,int>> => pair<count,num> 

2 -> 2
2 -> 1
1 -> 4
1 -> 3


*/