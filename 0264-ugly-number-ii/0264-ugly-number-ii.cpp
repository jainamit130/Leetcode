class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> st;
        st.insert(1);
        long num;
        for(int i=1;i<=n;i++){
            num = *st.begin();
            st.erase(num);
            st.insert(num*2);
            st.insert(num*3);
            st.insert(num*5);
        }
        return num;
    }
};

/*
1 => 2  3   5
2 => 4  6   10
3 => 9   15
5 => 25
4 => 8  12  20
6 => 18 30
10 => 50
9 => 

*/