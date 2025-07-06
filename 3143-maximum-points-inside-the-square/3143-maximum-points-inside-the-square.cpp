class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        vector<vector<int>> nums(points.size());//[point[0],point[1],index]
        for(int i=0;i<points.size();i++){
            nums[i]={points[i][0],points[i][1],i};
        }
        sort(nums.begin(),nums.end(),[](auto& lhs,auto& rhs){
            auto a = max(abs(lhs[0]),abs(lhs[1]));
            auto b = max(abs(rhs[0]),abs(rhs[1]));
            lhs={a,a,lhs[2]};
            rhs={b,b,rhs[2]};
            return a<b;
        });
        unordered_set<char> visited;
        visited.insert(s[nums[0][2]]);
        int flag=0;
        for(int i=1;i<nums.size();i++){
            if(visited.find(s[nums[i][2]])!=visited.end()){
                if(nums[i][0]==nums[i-1][0]){
                    int ans=visited.size();
                    int t=i-1;
                    while(t>=0 && nums[t][0]==nums[i][0]){
                        t--;
                        ans--;
                    }
                    return ans;
                }
                else 
                    return visited.size();
            }
            visited.insert(s[nums[i][2]]);
        }
        return s.length();
    }
};



/*






*/