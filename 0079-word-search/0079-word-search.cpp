class Solution {
public:
    bool search(int i, int j, int n, int m, vector<vector<char>>& board, int k, string word) {
        if (k == word.size()) return true;  // If we have matched all characters in the word, return true
        if (i == n || i < 0 || j < 0 || j == m || board[i][j] != word[k]) {
            return false;  // If current cell is out of bounds or does not match the current character in word, return false
        }
        
        char ch = board[i][j];  // Store the current character before exploring neighbors
        board[i][j] = '#';  // Mark the current cell as visited to avoid revisiting it
        
        // Explore neighbors in all four directions
        bool op1 = search(i + 1, j, n, m, board, k + 1, word);  // Down
        bool op2 = search(i - 1, j, n, m, board, k + 1, word);  // Up
        bool op3 = search(i, j + 1, n, m, board, k + 1, word);  // Right
        bool op4 = search(i, j - 1, n, m, board, k + 1, word);  // Left
        
        board[i][j] = ch;  // Restore the original character in the board
        
        return op1 || op2 || op3 || op4;  // Return true if any of the recursive calls return true
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();  // Number of rows in the board
        int m = board[0].size();  // Number of columns in the board
        int k = word.size();  // Length of the target word

        // Iterate over each cell in the board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Check if the word can be formed starting from the current cell
                if (search(i, j, n, m, board, 0, word)) {
                    return true;  // If found, return true
                }
            }
        }

        return false;  // If no match is found, return false
    }
};