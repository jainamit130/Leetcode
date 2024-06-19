class MyCalendar {
public:
    map<int,int> mp;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        int sum=0;
        mp[start]++;
        mp[end]--;
        for(auto [a,b]:mp){
            sum+=b;
            if(sum>1){
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */