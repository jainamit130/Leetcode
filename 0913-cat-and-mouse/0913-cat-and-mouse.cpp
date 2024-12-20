// flag 0 means it's the mouse's turn
// flag 1 means it's the cat's turn

class Solution {
private:
    int solve(int m, int c, int flag, vector<vector<int>>& graph, vector<vector<vector<int>>>& dp, set<pair<pair<int,int>,int>>& S) {

        // If the mouse reaches the hole (node 0), it wins
        if (m == 0) return 1;

        // If the cat catches the mouse, the cat wins
        if (m == c) return 2;

        // If we've already computed this state, return the stored result
        if (dp[m][c][flag] != -1) {
            return dp[m][c][flag];
        }

        // If this state is already in the set, it leads to a draw (cycle)
        if (S.find({{m, c}, flag}) != S.end()) return 0;
        else S.insert({{m, c}, flag});

        bool won = false;
        bool draw = false;

        if (flag == 0) { // Mouse's turn
            int temp;
            for (auto& i : graph[m]) { // Check all possible moves of the mouse
                temp = solve(i, c, 1, graph, dp, S); // Next turn is the cat's
                if (temp == 0) draw = true; // A draw is possible
                else if (temp == 1) { // If the mouse can win in any move
                    won = true;
                    break;
                }
            }
        }

        if (flag == 1) { // Cat's turn
            int temp;
            for (auto& i : graph[c]) { // Check all possible moves of the cat
                if (i == 0) continue; // Cat can't move to the hole (node 0)
                temp = solve(m, i, 0, graph, dp, S); // Next turn is the mouse's
                if (temp == 0) draw = true; // A draw is possible
                if (temp == 2) { // If the cat can win in any move
                    won = true;
                    break;
                }
            }
        }

        // Remove the state from the set
        S.erase({{m, c}, flag});

        // If one player can win, return the result
        if (won) {
            return dp[m][c][flag] = (flag == 0 ? 1 : 2); // Mouse's turn -> 1, Cat's turn -> 2
        } 
        else if (draw) {
            return dp[m][c][flag] = 0; // Draw
        } 
        else {
            return dp[m][c][flag] = (flag == 0 ? 2 : 1); // No winner, opposite player wins
        }
    }

public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<int>>> dp(51, vector<vector<int>>(51, vector<int>(2, -1)));
        set<pair<pair<int,int>,int>> S;
        int ans;

        for (int turn = 0; turn < n; turn++) {
            for (int i = 0; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    for (int k = 0; k <= 1; k++) {
                        if (dp[i][j][k] == 0) dp[i][j][k] = -1;
                    }
                }
            }
            ans = solve(1, 2, 0, graph, dp, S); // Mouse starts at 1, Cat at 2, Mouse's turn
        }

        return ans;
    }
};