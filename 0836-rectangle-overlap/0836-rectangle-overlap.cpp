class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return ((rec1[0]<rec2[0] && rec2[0]<rec1[2] && rec1[1]<rec2[3] && rec2[3]<rec1[3]) || //x3 y4
               (rec1[0]<rec2[2] && rec2[2]<rec1[2] && rec1[1]<rec2[3] && rec2[3]<rec1[3]) ||   //x4 y4
               (rec1[0]<rec2[0] && rec2[0]<rec1[2] && rec1[1]<rec2[1] && rec2[1]<rec1[3]) ||   //x3 y3
               (rec1[0]<rec2[2] && rec2[2]<rec1[2] && rec1[1]<rec2[1] && rec2[1]<rec1[3]) ||   //x4 y3
               (rec1[0]<=rec2[0] && rec2[2]<=rec1[2] && rec1[3]<=rec2[3] && rec2[1]>=rec2[3]) || 
               (rec2[0]<=rec1[0] && rec1[2]<=rec2[2] && rec2[3]<=rec1[3] && rec1[1]>=rec2[3]));
    }
};