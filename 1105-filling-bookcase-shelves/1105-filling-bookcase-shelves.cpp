class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        return solve(books,0,shelfWidth);
    }

    int solve(vector<vector<int>>& books,int index,int& shelfWidth){
        if(index>=books.size()){
            return 0;
        }

        int maxH=0;
        int currW=shelfWidth;
        int ans=INT_MAX;
        for(int i=index;i<books.size();i++){
            if(currW<books[i][0]){
                break;
            }
            currW-=books[i][0];
            maxH=max(maxH,books[i][1]);
            ans=min(ans,maxH+solve(books,i+1,shelfWidth));
        }
        return ans;
    }
};