/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        vector<vector<int>> prefix(grid.size(),vector<int>(grid[0].size(),0));
        prefix[0][0]=grid[0][0];
        for(int i=1;i<grid.size();i++){
            prefix[i][0]=prefix[i-1][0]+grid[i][0];
        }
        for(int j=1;j<grid.size();j++){
            prefix[0][j]=prefix[0][j-1]+grid[0][j];
        }
        for(int i=1;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]+grid[i][j]-prefix[i-1][j-1];
            }
        }
        return constructQuadTree(grid,prefix,0,0,prefix.size()-1,prefix[0].size()-1);
    }
       
    Node* constructQuadTree(vector<vector<int>>& grid,vector<vector<int>>& prefix,int startRow,int startCol,int endRow,int endCol){
        if(startRow==endRow && startCol==endCol){
            return new Node(grid[startRow][startCol],true);
        }

        int toBeAdded = 0;
        int toBeSubtracted=0;
        if(startRow-1>=0){
            toBeSubtracted+=prefix[startRow-1][endCol];
            if(startCol-1>=0)
                toBeAdded=prefix[startRow-1][startCol-1];
        } 
        if(startCol-1>=0){
            toBeSubtracted+=prefix[endRow][startCol-1];
        }
        int sum=prefix[endRow][endCol]+toBeAdded-toBeSubtracted;
        if((endRow-startRow+1)*(endCol-startCol+1)==sum){
            return new Node(1,true);
        }
        if(sum==0){
            return new Node(0,true);
        }

        Node* node = new Node(0,0);
        node->topLeft=constructQuadTree(grid,prefix,startRow,startCol,endRow/2,endCol/2);
        node->topRight=constructQuadTree(grid,prefix,startRow,(endCol/2)+1,endRow/2,endCol);
        node->bottomLeft=constructQuadTree(grid,prefix,(endRow/2)+1,startCOl,endRow,endCol/2);
        node->bottomRight=constructQuadTree(grid,prefix,(endRow/2)+1,(endCol/2)+1,endRow,endCol);
        return node;
    }
};



/*

1   2   3   4   4   4   4   4 
2   4   6   8   8   8   8   8 
3   6   9   12  13  14  15  16 
4   8   12  16  18  20  22  24 
5   10  15  20  22  24  26  28 
6   12  18  24  26  28  30  32 
7   14  21  28  30  32  34  36 
8   16  24  32  34  36  38  40 








*/