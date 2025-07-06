class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int,set<int>> obsRow;
        unordered_map<int,set<int>> obsCol;
        for(int i=0;i<obstacles.size();i++){
            obsRow[obstacles[i][0]].insert(obstacles[i][1]);
            obsCol[obstacles[i][1]].insert(obstacles[i][0]);
        }

        int isRowActive = 0;
        int row=0;
        int col=0;
        int rowD = 0;
        int colD = 1;
        int ans=0;
        for(int i=0;i<commands.size();){
            if(commands[i]==-2){
                if(isRowActive){
                    if(rowD<0){
                        colD=-1;
                    } else {
                        colD=1;
                    }
                } else {
                    if(colD>0){
                        rowD=-1;
                    } else {
                        rowD=1;
                    }
                }
                isRowActive=!isRowActive;
                i++;
            } else if(commands[i]==-1){
                if(isRowActive){
                    if(rowD<0){
                        colD=1;
                    } else {
                        colD=-1;
                    }
                } else {
                    if(colD>0){
                        rowD=1;
                    } else {
                        rowD=-1;
                    }
                }
                isRowActive=!isRowActive;
                i++;
            } else {
                int flag=0;
                while(i<commands.size() && commands[i]>0){
                    if(flag==1){
                        i++;
                        continue;
                    }
                    if(isRowActive){
                        if(rowD>0){
                            for(auto itr=obsCol[col].begin();itr!=obsCol[col].end();itr++){
                                int obsR= *itr;
                                if(row<obsR && obsR<row+commands[i]){
                                    row=obsR-1;
                                    flag=1;
                                    break;
                                } 
                            }
                        } else {
                            for(auto itr=obsCol[col].rbegin();itr!=obsCol[col].rend();itr++){
                                int obsR= *itr;
                                if(row>obsR && obsR>row-commands[i]){
                                    row=obsR+1;
                                    flag=1;
                                    break;
                                } 
                            }
                        }
                        if(flag==0)
                            row+=commands[i]*(rowD);
                    } else {
                        if(colD>0){
                            for(auto itr=obsRow[row].begin();itr!=obsRow[row].end();itr++){
                                int obsC= *itr;
                                if(col<obsC && obsC<col+commands[i]){
                                    col=obsC-1;
                                    flag=1;
                                    break;
                                } 
                            }
                        } else {
                            for(auto itr=obsRow[row].rbegin();itr!=obsRow[row].rend();itr++){
                                int obsC= *itr;
                                if(col>obsC && obsC>col-commands[i]){
                                    col=obsC+1;
                                    flag=1;
                                    break;
                                } 
                            }
                        }
                        if(flag==0)
                            col+=commands[i]*(colD);
                    }
                    ans=max(ans,(row*row)+(col*col));
                    i++;
                }
            }
            ans=max(ans,(row*row)+(col*col));
        }
        return ans;
    }
};


/*


-2 => left 90 deg
-1 => right 90 deg
        11      21    32       4       5       6       7       8       9
-1 => Row+ => Col- => Row- => Col+ => Row+ => Col- => Row- => Col+ => Row+ => Col- => Row- => Col+
-2 => Row- => Col+ => Row+ => Col-

*/