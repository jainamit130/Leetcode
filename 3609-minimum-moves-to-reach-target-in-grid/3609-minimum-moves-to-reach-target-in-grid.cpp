class Solution {
public:
     int minMoves(int sx, int sy, int tx, int ty) {
        if (tx < sx || ty < sy) return -1;
        if (tx == sx && ty == sy) return 0;

        if (tx > ty) {
            if (tx > 2 * ty) {
                if (tx % 2 != 0) return -1;
                int next = minMoves(sx, sy, tx / 2, ty);
                return next == -1 ? -1 : next + 1;
            } else {
                int next = minMoves(sx, sy, tx - ty, ty);
                return next == -1 ? -1 : next + 1;
            }
        } else if (ty > tx) {
            if (ty > 2 * tx) {
                if (ty % 2 != 0) return -1;
                int next = minMoves(sx, sy, tx, ty / 2);
                return next == -1 ? -1 : next + 1;
            } else {
                int next = minMoves(sx, sy, tx, ty - tx);
                return next == -1 ? -1 : next + 1;
            }
        } else {
            if (sx == 0 && sy == 0 && (tx != 0 || ty != 0)) return -1;
            if (sx == 0) {
                int next = minMoves(sx, sy, 0, ty);
                return next == -1 ? -1 : next + 1;
            }
            if (sy == 0) {
                int next = minMoves(sx, sy, tx, 0);
                return next == -1 ? -1 : next + 1;
            }
            return -1;
        }
    }
};