/**
 * @param {number} m
 * @param {number} n
 * @param {number[][]} guards
 * @param {number[][]} walls
 * @return {number}
 */
var countUnguarded = function(m, n, guards, walls) {
    let grid = Array.from({ length: m }, () => Array(n).fill(0));
    let colGuard = new Array(n).fill(false);
    let revColGuard = new Array(n).fill(false);

    // Mark guards on the grid
    for (let [x, y] of guards) {
        grid[x][y] = 1; // Guard
    }

    // Mark walls on the grid
    for (let [x, y] of walls) {
        grid[x][y] = 2; // Wall
    }

    for (let i = 0; i < m; i++) {
        let revI = m - i - 1;
        let isGuarded = [false];
        let isRevGuarded = [false];

        for (let j = 0; j < n; j++) {
            let revJ = n - j - 1;
            markCell(i, j, colGuard, isGuarded, grid);
            markCell(revI, revJ, revColGuard, isRevGuarded, grid);
        }
    }

    // Count unguarded cells
    let ans = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 0) {
                ans++;
            }
        }
    }

    return ans;
};

function markCell(i, j, colGuard, isGuarded, grid) {
    if ((isGuarded[0] || colGuard[j]) && grid[i][j] === 0) {
        grid[i][j] = 3; // Guarded
    }

    if (grid[i][j] === 1) {
        colGuard[j] = true;
        isGuarded[0] = true;
    } else if (grid[i][j] === 2) {
        colGuard[j] = false;
        isGuarded[0] = false;
    }
}
