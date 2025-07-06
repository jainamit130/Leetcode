class DetectSquares {
public:
    vector<vector<int>> points;
    DetectSquares() {
        points = vector<vector<int>>(1001, vector<int>(1001));
    }
    
    void add(vector<int> point) {
        points[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x=point[0];
        int y=point[1];
        int ans=0;
        //All X of Same Y && All Y of Same X
        vector<vector<int>> directions={{1,1},{1,-1},{-1,1},{-1,-1}};
        for(int k=0;k<directions.size();k++){
            int i=directions[k][0];
            int j=directions[k][1];
            while(1){
                int nx=x+i;
                int ny=y+j;
                if(nx>1000 || ny>1000 || nx<0 || ny<0)
                    break;
                //x,y ; nx,y; x,ny; nx,ny
                ans+=(points[nx][ny]*points[nx][y]*points[x][ny]);
                i+=directions[k][0];
                j+=directions[k][1];
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */