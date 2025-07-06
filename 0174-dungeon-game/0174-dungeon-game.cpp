class Solution{
    public:
int dp(vector<vector<int>> &mat, vector<vector<int>> &cache , int i=0, int j=0)
    {
        int n = mat.size();
        int m = mat[0].size();    
        
        if(i == n || j == m)    return 1e9; 
        
        if(i == n-1 and j == m-1)
            return (mat[i][j] <= 0) ? -mat[i][j] + 1 : 1;

        if( cache[i][j] != 1e9)
            return cache[i][j];
        
        int IfWeGoRight = dp(mat , cache , i , j+1);
        int IfWeGoDown = dp(mat , cache , i+1 , j);
        
        int minHealthRequired =  min(IfWeGoRight , IfWeGoDown) -mat[i][j];
        
        cache[i][j] = ( minHealthRequired <= 0 ) ? 1 : minHealthRequired;      
        return cache[i][j];
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int n = dungeon.size();
        int m = dungeon[0].size();
        
        vector<vector<int>> cache(n , vector<int>(m , 1e9));
        
        return dp(dungeon, cache);     
    }
};