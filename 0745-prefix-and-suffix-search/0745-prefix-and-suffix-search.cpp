class Trie{

    public :
    Trie *child[26];
    vector<int> index;
    Trie(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};


void insert_trie(string str,int i,Trie *root){
    
    Trie *temp = root;
    for(char ch:str){
        if(temp->child[ch-'a']==NULL){
            temp->child[ch-'a']=new Trie();
        }
        temp = temp->child[ch-'a'];
        temp->index.push_back(i);
    }
}


vector<int> find_string(string str,Trie *root){
    Trie *temp = root;
    for(char ch:str){
        if(temp->child[ch-'a']==NULL){
            return {};
        }
        temp = temp->child[ch-'a'];
    }
    return temp->index;
}


class WordFilter {
public:
    
    Trie *prefix,*suffix;
    
    WordFilter(vector<string>& words) {
        prefix = new Trie();
        suffix = new Trie();
        map<string,int> dic;
        int len = words.size();
        for(int i=0;i<len;i++){
            dic[words[i]]=i;
            
        }
        for(auto i:dic){
            string temp = i.first;
            int index = i.second;
            
            insert_trie(temp,index,prefix);
            reverse(temp.begin(),temp.end());
            insert_trie(temp,index,suffix);
        }
    }
    
    int f(string p, string s) {
        vector<int> pre = find_string(p,prefix);
        reverse(s.begin(),s.end());
        vector<int> suf = find_string(s,suffix);
        
        
        set<int> st;
        sort(pre.begin(),pre.end());
        for(int i:suf){
            st.insert(i);
        }
        int n = pre.size();
        
        for(int i=n-1;i>=0;i--){
            if(st.find(pre[i])!=st.end()) return pre[i];
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */