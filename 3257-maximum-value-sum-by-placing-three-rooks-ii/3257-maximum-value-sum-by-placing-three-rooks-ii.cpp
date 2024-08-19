class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int m=board.size(); // row size
        int n=board[0].size(); // col size
        vector<vector<pair<int,int>>> max3(m);
        //O(m*n*log(3)) = O(m*n)
        for(int i=0;i<m;i++){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
            for(int j=0;j<n;j++){
                minHeap.push({board[i][j],j});
                if(minHeap.size()>3){
                    minHeap.pop();
                }
            }

            while(!minHeap.empty()){
                max3[i].push_back(minHeap.top());
                minHeap.pop();
            }
        }

        //Brute Force O(m * 27)
        long long ans=LLONG_MIN;
        for(int row1=0;row1<m;row1++){
            for(int j=0;j<3;j++){
                int val1=max3[row1][j].first;
                int col1=max3[row1][j].second;
                priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minHeap;
                vector<vector<int>> max4AmoungMax3;
                for(int row2=0;row2<m;row2++){
                    for(int t=0;t<3;t++){
                        int col2=max3[row2][t].second;
                        if(row1==row2 || col1==col2){
                            continue;
                        }
                        int val2=max3[row2][t].first;
                        minHeap.push({val2,row2,col2});
                        if(minHeap.size()>4){
                            minHeap.pop();
                        }
                    }
                }

                while(!minHeap.empty()){
                    max4AmoungMax3.push_back(minHeap.top());
                    minHeap.pop();
                }

                for(int l=0;l<3;l++){
                    int val2=max4AmoungMax3[l][0];
                    int row2=max4AmoungMax3[l][1];
                    int col2=max4AmoungMax3[l][2];
                    for(int p=l+1;p<4;p++){
                        int row3=max4AmoungMax3[p][1];
                        int col3=max4AmoungMax3[p][2];
                        int val3=max4AmoungMax3[p][0];
                        if(row3==row2 || col3==col2){
                            continue;
                        }
                        ans=max(ans,(long long)val1+val2+val3);
                    }
                }
            }            
        }
        return ans;
    }
};