class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        // centre.raduis -> points
        map<vector<double>,vector<vector<int>>> mp;
        for(int i=0;i<points.size();i++) {
            for(int j=i+1;j<points.size();j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                double cenX = (x1+x2)/2.0;
                double cenY = (y1+y2)/2.0; 
                double radius = getDist(x1,y1,x2,y2)/2.0;
                cout<<x1<<","<<y1<<" and "<<x2<<","<<y2<<" -> "<<cenX<<","<<cenY<<" ; "<<radius<<endl;
                mp[{cenX,cenY,radius}].push_back({x1,y1,x2,y2});
            }
        }

        double ans = INT_MAX;

        for(auto [centreAndRadius,pointPairs]:mp) {
            for(int i=0;i<pointPairs.size();i++) {
                int x1 = pointPairs[i][0];
                int y1 = pointPairs[i][1]; 
                int x2 = pointPairs[i][2]; 
                int y2 = pointPairs[i][3]; 
                for(int j=i+1;j<pointPairs.size();j++) {
                    int x3 = pointPairs[j][0];
                    int y3 = pointPairs[j][1];
                    int x4 = pointPairs[j][2];
                    int y4 = pointPairs[j][3];
                    
                    double dist1 = getDist(x1,y1,x3,y3);
                    double dist2 = getDist(x3,y3,x4,y4);
                    

                    ans = min(ans,dist1*dist2);
                }
            }
        }
        return ans==INT_MAX?0:ans;
    }

    double getDist(int x1,int y1,int x2,int y2) {
        return (int)sqrt(pow(y2-y1,2)+pow(x2-x1,2));
    }
};