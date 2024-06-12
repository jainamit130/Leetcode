class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        unordered_set<int> st1;
        int ans=INT_MAX;
        for(int i=0;i<arr.size();i++){
            unordered_set<int> st2;
            st2.insert(arr[i]);
            for(auto a:st1){
                st2.insert(arr[i]&a);
            }
            for(auto a:st2){
                ans=min(ans,abs(a-target));
            }
            st1=st2;
        }
        return ans;
    }
};