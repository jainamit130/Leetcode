class Solution {
public:
    int findSlope(vector<int>& p1,vector<int>& p2,vector<int>& p3){
        // (y3-y2)(x2-x1)-(y2-y1)(x3-x2)
        return (p3[1]-p2[1])*(p2[0]-p1[0])-(p2[1]-p1[1])*(p3[0]-p2[0]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(),trees.end());
        vector<vector<int>> lower;
        vector<vector<int>> upper;

        for(auto& tree:trees){
            int l=lower.size();
            int r=upper.size();

            while(l>2 && findSlope(lower[l-2],lower[l-1],tree)>0){
                l--;
                lower.pop_back();
            }

            while(r>2 && findSlope(upper[r-2],upper[r-1],tree)<0){
                r--;
                upper.pop_back();
            }

            lower.push_back(tree);
            upper.push_back(tree);
        }

        set<vector<int>> st(lower.begin(),lower.end());
        for(auto& upperPoint:upper){
            st.insert(upperPoint);
        }

        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
    
};