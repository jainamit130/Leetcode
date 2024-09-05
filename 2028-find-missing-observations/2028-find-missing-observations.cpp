class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sumN = 0;
        int sumM = 0;
        for(int i=0;i<rolls.size();i++){
            sumM+=rolls[i];
        }
        sumN = (rolls.size() + n)*mean - sumM;
        vector<int> ans;
        cout<<sumN<<endl;
        int maxSumN = n*6;
        int minSumN = n;
        if(sumN<minSumN || sumN>maxSumN){
            return {};
        }
        int rem=n;
        for(int i=0;i<n;i++){
            int evenCont = sumN/rem;
            if(evenCont>6 || evenCont<=0){
                return {};
            }
            ans.push_back(evenCont);
            sumN-=evenCont;
            rem--;
        } 
        return ans;
    }
};


/*
3   *   7 - (1+5+6) 
21-12=9

9/4 = 2



*/