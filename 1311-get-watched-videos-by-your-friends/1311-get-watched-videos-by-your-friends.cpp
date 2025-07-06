class comparator {
    public:
        bool operator()(pair<int,string>& lhs,pair<int,string>& rhs) {
            if(lhs.first==rhs.first) return lhs.second>rhs.second;
            return lhs.first<rhs.first;
        }
};

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int> q;
        int n = friends.size();
        unordered_map<string,int> mp;
        q.push(id);
        vector<int> visited(n);
        visited[id]=1;
        while(!q.empty()) {
            int size = q.size();
            while(size) {
                int currId = q.front();
                q.pop();
                size--;
                if(level==0) {
                    for(int i=0;i<watchedVideos[currId].size();i++) mp[watchedVideos[currId][i]]++;
                }
                for(int i=0;i<friends[currId].size();i++) {
                    int neigh = friends[currId][i];
                    if(visited[neigh]==0) {
                        visited[neigh]=1;
                        q.push(neigh);
                    }
                }
            }
            level--;
        }

        priority_queue<pair<int,string>,vector<pair<int,string>>,comparator> pq;
        for(auto [str,freq]:mp) {
            pq.push({freq,str});
        }
        vector<string> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};


/*

Given:
vector<vector<string>> watchedVideos
vector<vector<int>> friends




*/