class Solution {
public:
    using pii=vector<int>;
    vector<vector<int>> combo = {{0,1},{2,3},{2,1},{0,3}};
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        long givenTotalArea=0;
        set<pii> st;
        for(auto points:rectangles){
            for(auto p:combo){
                processSet(st,{points[p[0]],points[p[1]]});
            }
            givenTotalArea += (long)(points[2]-points[0])*(points[3]-points[1]);
        }

        if(st.size()!=4){
            return false;
        }
        vector<pii> points;
        for(auto s:st){
            points.push_back(s);
        }

        return (long)(points[1][1]-points[0][1])*(points[2][0]-points[0][0])==givenTotalArea;
    }

    void processSet(set<pii>& st,pii point){
        if(st.find(point)!=st.end()){
            st.erase(point);
        } else {
            st.insert(point);
        }
    }
};