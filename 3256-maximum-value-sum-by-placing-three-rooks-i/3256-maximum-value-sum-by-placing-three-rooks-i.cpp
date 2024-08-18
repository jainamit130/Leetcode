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

        //Brute Force O(m^3 * 27)
        long long ans=LLONG_MIN;
        for(int i=0;i<m-2;i++){
            for(int j=i+1;j<m-1;j++){
                for(int k=j+1;k<m;k++){
                    for(auto [val1,col1]:max3[i]){
                        for(auto [val2,col2]:max3[j]){
                            if(col1==col2){
                                continue;
                            }
                            for(auto [val3,col3]:max3[k]){
                                if(col1==col3 || col2==col3){
                                  continue;
                                }
                                ans=max(ans,(long long)val1+val2+val3);
                            }    
                        }
                    }
                }
            }
        }
        return ans;
    }
};