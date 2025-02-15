class Solution {
public:
    double epsilon = 1e-5;

    double separateSquares(vector<vector<int>>& squares) {
        double start = 0;
        double end = 1e18; 

        while (end - start > epsilon) {
            double mid = start + (end - start) / 2.0;
            double areaAbove = calculateAreaAbove(squares, mid);
            double areaBelow = calculateAreaBelow(squares, mid);

            if (abs(areaAbove - areaBelow) < epsilon) {
                end = mid;
            } else if (areaAbove > areaBelow) {
                start = mid;
            } else {
                end = mid;
            }
        }

        return start; 
    }

    double calculateAreaAbove(vector<vector<int>>& squares, double y) {
        double area = 0;
        for (const auto& square : squares) {
            double y1 = square[1]; 
            double y2 = square[1] + square[2]; 
            if (y2 > y) {
                double height = max(0.0, y2 - max(y, y1));
                area += height * square[2];
            }
        }
        return area;
    }

    double calculateAreaBelow(vector<vector<int>>& squares, double y) {
        double area = 0;
        for (const auto& square : squares) {
            double y1 = square[1]; 
            double y2 = square[1] + square[2]; 
            if (y1 < y) {
                double height = max(0.0, min(y, y2) - y1);
                area += height * square[2];
            }
        }
        return area;
    }
};

/*





*/