class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int ans=0;
        int n=colors.size();
        for(int i=0;i<n;i++){
            int first=colors[i];
            int second=colors[(i+1)%n];
            int third=colors[(i+2)%n];
            if(first==third && first!=second){
                ans++;
            }
        }
        return ans;
    }
};