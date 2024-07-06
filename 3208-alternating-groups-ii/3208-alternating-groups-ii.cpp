class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        deque<int> dq;
        int ans=0;
        int n=colors.size();
        for(int i=0;i<=n+k-1;i++){
            int index=i%n;
            if(dq.size()==k){
                ans++;
                dq.pop_front();
            }

            if(!dq.empty() && dq.back()==colors[index]){
                dq.clear();
            }
            dq.push_back(colors[index]);
        }
        return ans;
    }
};