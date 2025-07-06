class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> st;
        st.insert(1);
        int smallest=1;
        while(n){
            smallest=*st.begin();
            st.erase(smallest);
            st.insert((long)smallest*2);
            st.insert((long)smallest*3);
            st.insert((long)smallest*5);
            n--;
        }
        return smallest;
    }
};


/*

1   2   3   4   5   6   8   9   10  12



*/