class Node {
    public:
        Node* prev;
        Node* next;
        string val;
        Node(string key){
            prev=NULL;
            next=NULL;
            val=key;
        }
};

using pni=pair<Node*,int>;
class AllOne {
public:
    unordered_map<string,pni> mp;
    Node* mini;
    Node* maxi;

    AllOne() {
        mini=NULL;
        maxi=NULL;
    }
    
    void inc(string key) {
        if(mp.find(key)!=mp.end()){
            if(maxi->val==key || (mp[key].first->next && mp[mp[key].first->next->val].second>=mp[key].second+1)){
                mp[key].second++;
                return;
            }
            Node* temp=deleteNode(mp[key].first,true);
            while(temp && mp[temp->val].second<=mp[key].second+1){
                temp=temp->next;
            }
            Node* newPtr=new Node(key);
            if(temp){
                newPtr->next=temp;
                newPtr->prev=temp->prev;
                temp->prev=newPtr;
                newPtr->prev->next=newPtr;
            } else {
                newPtr->prev=maxi;
                maxi->next=newPtr;
                maxi=newPtr;
            }
            int count=mp[key].second;
            mp.erase(key);
            mp[key]={newPtr,count+1};
        } else {
            Node* temp=new Node(key);
            mp[key]={temp,1};
            temp->next=mini;
            if(mini==NULL){
                mini=temp;
                maxi=temp;
            } else {
                mini->prev=temp;
                mini=temp;
            }
        }
    }

    Node* deleteNode(Node* toDel,bool isInc){
        Node* previous = toDel->prev;
        if(previous==NULL){
            if(toDel->next){
                Node* next=toDel->next;
                next->prev=previous;
                mini=next;
            } else {
                mini=NULL;
                maxi=NULL;
            }
            return toDel->next;
        } else {
            if(maxi==toDel){
                if(toDel->next){
                    maxi=toDel->next;
                } else {
                    maxi=toDel->prev;
                }
            }
            if(mini==toDel){
                if(toDel->prev){
                    mini=toDel->prev;
                } else {
                    mini=toDel->next;
                }
            }
            previous->next=toDel->next;
            if(toDel->next){
                toDel->next->prev=previous;
            }
        }
        return previous;
    }
    
    void dec(string key) {
        int count=mp[key].second;
        if(mini->val==key || (mp[key].first->prev && mp[mp[key].first->prev->val].second<=mp[key].second-1)){
            if(count==1){
                deleteNode(mp[key].first,false);
                mp.erase(key);
            } else {
                mp[key].second--;
            }
            return;
        }

        Node* temp=deleteNode(mp[key].first,false);
        if(count==1){
            mp.erase(key);
        } else {
            while(temp && mp[temp->val].second>=mp[key].second-1){
                temp=temp->prev;
            }

            Node* newPtr=new Node(key);
            if(temp){
                newPtr->prev=temp;
                newPtr->next=temp->next;
                temp->next=newPtr;
            } else {
                newPtr->next=mini;
                mini->prev=newPtr;
                mini=newPtr;
            }
            mp.erase(key);
            mp[key]={newPtr,count-1};
        }
    }
    
    string getMaxKey() {
        if(maxi==NULL){
            return "";
        }
        return maxi->val;
    }
    
    string getMinKey() {
        if(mini==NULL){
            return "";
        }
        return mini->val;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */