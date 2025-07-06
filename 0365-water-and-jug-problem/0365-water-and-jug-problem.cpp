class Solution {
public:
    set<pair<int,int>> st;
    bool canMeasureWater(int x, int y, int target) {
        if(x+y<target) return false;
        return solve(0,0,x,y,target);
    }

    bool solve(int vol1,int vol2,int x,int y,int target) {
        if(vol1+vol2==target) return true;
        if(st.find({vol1,vol2})!=st.end()) return false;
        bool ans = false;
        st.insert({vol1,vol2});
        ans = ans || solve(min(vol1+vol2,x),max(0,vol2-vol1),x,y,target);
        ans = ans || solve(max(vol1-vol2,0),min(y,vol2+vol1),x,y,target);
        ans = ans || solve(vol1,0,x,y,target);
        ans = ans || solve(0,vol2,x,y,target);
        ans = ans || solve(x,vol2,x,y,target);
        ans = ans || solve(vol1,y,x,y,target);
        return ans;
    }
};



/*
Ex:

x=3
y=5
target = 4

3,  5



Given:
int x => >0
int y => >0
int target => >0

operations => empty completely
           => fill completely
           => fill from other as much as possible

Approach: Top down DP

States 
0,0

x,y

x*y

*/