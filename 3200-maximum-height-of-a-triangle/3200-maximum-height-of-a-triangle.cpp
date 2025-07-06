class Solution {
    public:
    int maxHeightOfTriangle(int redStones, int blueStones) {
        return max(computeHeight(redStones, blueStones), computeHeight(blueStones, redStones));
    }
    int computeHeight(int stonesA, int stonesB) {
        int height = 0;
        for (int layer = 0; layer < 100; ++layer) {
            if (layer % 2 == 0) {
                if (stonesA >= layer + 1) {
                    ++height;
                    stonesA -= (layer + 1);
                } else {
                    return height;
                }
            } else {
                if (stonesB >= layer + 1) {
                    ++height;
                    stonesB -= (layer + 1);
                } else {
                    return height;
                }
            }
        }
        return height;
    }
};