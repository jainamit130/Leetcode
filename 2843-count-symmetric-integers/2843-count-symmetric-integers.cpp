class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i=low;i<=high;i++) {
            string num = to_string(i);
            if(num.length()%2!=0) continue;
            int sum = 0;
            for(int j=0;j<num.length()/2;j++) {
                sum+=num[j]-num[num.length()-j-1];
            }
            if(sum==0) ans++;
        }
        return ans;
    }
};

/*
given => low,high


*/