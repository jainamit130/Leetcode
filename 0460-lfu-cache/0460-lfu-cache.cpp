class List {
    public:
        int val;
        List* prev;
        List* next;
        List(int value){
            val=value;
            prev=NULL;
            next=NULL;
        }

};
        vector<List*> deleteKey(List* head,List* node,List* mru,List* lru){
            List* prevPtr=node->prev;
            List* nextPtr=node->next;
            if(mru->val==node->val){
                mru=mru->next;
            }
            if(lru->val==node->val){
                lru=lru->prev;
            }
            if(prevPtr){
                prevPtr->next=nextPtr;
            }
            if(nextPtr){
                nextPtr->prev=prevPtr;
            }
            if(!nextPtr && !prevPtr)
                return {NULL,NULL,NULL};
            return {head,mru,lru};
        }

        pair<vector<List*>,List*> insertKey(List* node,List* mru,List* lru,int key){
            List* newNode = new List(key);
            if(lru==NULL){
                lru=newNode;
            } 
            mru=newNode;
            newNode->next = node;
            if(node)
                node->prev=newNode;
            return {{newNode,mru,lru},newNode};
        }

class LFUCache {
public:
    unordered_map<int,List*> mpNode;
    unordered_map<int,pair<int,int>> mpCountVal;
    map<int,vector<List*>> mp;
    int currSize;
    int size;
    LFUCache(int capacity) {
        currSize=0;
        size=capacity;
    }
    
    int get(int key) {
        if(mpCountVal.find(key)==mpCountVal.end()){
            return -1;
        }
        int count = mpCountVal[key].first;
        int value = mpCountVal[key].second;
        vector<List*> newDeletedList = deleteKey(mp[count][0],mpNode[key],mp[count][1],mp[count][2]);
        if(newDeletedList[0]==NULL){
            mp.erase(count);
        } else {
            mp[count]=newDeletedList;
        }
        if(mp.find(count+1)!=mp.end()){
            auto [newList,newNode]=insertKey(mp[count+1][0],mp[count+1][1],mp[count+1][2],key);
            mp[count+1]=newList;
            mpNode[key]=newNode;
            mpCountVal[key].first=count+1;
        } else {
            auto [newList,newNode]=insertKey(NULL,NULL,NULL,key);
            mp[count+1]=newList;
            mpNode[key]=newNode;
            mpCountVal[key].first=count+1;
        }
        return value;
    }
    
    void put(int key, int value) {
        if(currSize==size){
            int toDelete=mp.begin()->second[2]->val;
            mpCountVal.erase(toDelete);
            mpNode.erase(toDelete);
            int firstCount = mp.begin()->first;
            vector<List*> newDeletedList=deleteKey(mp[firstCount][0],mp[firstCount][2],mp[firstCount][1],mp[firstCount][2]);
            if(newDeletedList[0]==NULL){
            mp.erase(firstCount);
        } else {
            mp[firstCount]=newDeletedList;
        }
            currSize--;
        }
        
        if(mp.find(1)==mp.end()){
            auto [newList,newNode]=insertKey(NULL,NULL,NULL,key);
            mp[1]=newList;
            mpNode[key]=newNode;
        } else {
            auto [newList,newNode]=insertKey(mp[1][0],mp[1][1],mp[1][2],key);
            mp[1]=newList;
            mpNode[key]=newNode;
        }
        mpCountVal[key]={1,value};
        currSize++;
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */