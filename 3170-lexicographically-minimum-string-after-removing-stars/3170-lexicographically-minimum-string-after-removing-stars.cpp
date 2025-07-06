class Solution {
public:
    string clearStars(string s) {
    auto comparator = [](auto lhs, auto rhs) {
        if (lhs.first == rhs.first) {
            return lhs.second < rhs.second;
        }
        return lhs.first > rhs.first;
    };

    priority_queue<pair<char,int>,vector<pair<char,int>>, decltype(comparator)> minHeap(comparator);
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                minHeap.pop();
            } else {
                minHeap.push({s[i],i});
            }
        }
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> minHeap1;
        while(!minHeap.empty()){
            minHeap1.push({minHeap.top().second,minHeap.top().first});
            minHeap.pop();
        }
        string ans="";
        while(!minHeap1.empty()){
            ans+=minHeap1.top().second;
            minHeap1.pop();
        }
        return ans;
    }
};

/*

a   a   b   a   *


*/