class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<int, int> state_map;
        int zero_row = -1, zero_col = -1;
        for (int row = 0; row < 2; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (board[row][col] == 0)
                {
                    zero_row = row;
                    zero_col = col;
                }
            }
        }
        
        solve(board, state_map, zero_row, zero_col, 0);
        return state_map.find(123450) == state_map.end() ? -1 : state_map[123450];
        
    }
    
    int board_to_int(vector<vector<int>>& board)
    {
        int value = 0;
        for (auto& v : board[0])
        {
            value = value * 10 + v;
        }
        for (auto& v : board[1])
        {
            value = value * 10 + v;
        }
        return value;
    }
    
    void solve(vector<vector<int>>& board, unordered_map<int, int>& state_map, int row, int col, int moves)
    {
        int board_value = board_to_int(board);
        state_map[board_value] = moves;
        if (board_value == 123450)  return;
        
        
        //move right
        if (col <= 1)
        {
            swap(board[row][col], board[row][col + 1]);
            int new_value = board_to_int(board);
            if (state_map.find(new_value) == state_map.end() || moves + 1 < state_map[new_value])
            {
                solve(board, state_map, row, col + 1, moves + 1);
            }
            swap(board[row][col + 1], board[row][col]);
        }
        
        //move left
        if (col >= 1)
        {
            swap(board[row][col], board[row][col - 1]);
            int new_value = board_to_int(board);
            if (state_map.find(new_value) == state_map.end() || moves + 1 < state_map[new_value])
            {
                solve(board, state_map, row, col - 1, moves + 1);
            }
            swap(board[row][col], board[row][col - 1]);
        }
        
        
        //move up
        if (row == 1)
        {
            swap(board[row][col], board[row - 1][col]);
            int new_value = board_to_int(board);
            if (state_map.find(new_value) == state_map.end() || moves + 1 < state_map[new_value])
            {
                solve(board, state_map, row - 1, col, moves + 1);
            }
            swap(board[row][col], board[row - 1][col]);
        }
        
        
        //move down
        if (row == 0)
        {
            swap(board[row][col], board[row + 1][col]);
            int new_value = board_to_int(board);
            if (state_map.find(new_value) == state_map.end() || moves + 1 < state_map[new_value])
            {
                solve(board, state_map, row + 1, col, moves + 1);
            }
            swap(board[row][col], board[row + 1][col]);
        }
    }
};