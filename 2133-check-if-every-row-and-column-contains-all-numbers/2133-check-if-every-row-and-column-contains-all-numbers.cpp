class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int sum = 0;
        int n = matrix.size();
        for(int i=1;i<=n;i++) {
            sum+=i;
        }
        vector<int> freq(n);
        vector<int> col(n);
        for(int i=0;i<n;i++) {
            int sumR = 0;
            vector<int> freqR(n);
            for(int j=0;j<n;j++) {
                if(matrix[i][j]<=0 || matrix[i][j]>n) return false;
                freq[matrix[i][j]-1]++;
                freqR[matrix[i][j]-1]++;
                sumR += matrix[i][j];
                col[j]+=matrix[i][j];
            }
            for(int i=0;i<n;i++) {
                if(freqR[i]!=1) return false;
            }
            if(sumR!=sum) return false;
        }

        for(int i=0;i<n;i++) {
            if(col[i]!=sum || freq[i]!=n) return false;
        }
        return true;
    }
};

/*


4   2   2   2 => 10
1   1   4   4 => 10
3   3   1   3 => 10
2   4   3   1



*/