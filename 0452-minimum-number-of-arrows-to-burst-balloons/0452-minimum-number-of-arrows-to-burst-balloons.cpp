class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        // cout<<"Sorted"<<endl;
        // for(int i=0;i<points.size();i++){
        //     cout<<points[i][0]<<" "<<points[i][1]<<endl;
        // }
        int count=0;
        for(int i=0;i<points.size();i++){
            int x=points[i][0];
            int y=points[i][1];
            int j=i+1;
            // cout<<"Checking: "<<x<<" "<<y<<endl;
            while(j<points.size()){
                if(points[j][0]>y)
                    break;
                // cout<<points[i][0]<<" "<<points[i][1]<<" -> ";
                x=max(x,points[j][0]);
                y=min(y,points[j][1]);
                // cout<<x<<" "<<y<<endl;
                j++;
                i++;
            }
            count++;
        }
        return count;
    }
};