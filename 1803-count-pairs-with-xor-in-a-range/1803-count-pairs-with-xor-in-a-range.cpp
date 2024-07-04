class Trie {
    public:
    unordered_map<int,Trie*> children;
    int count;
    bool end;

    Trie(){
        count=0;
        end=false;
    }

    void printTrie(int level = 0) {
        // Print current node
        cout << string(level * 2, ' ') << "└─ ";
        cout << "Count: " << count;
        if (end) {
            cout << " (end)";
        }
        cout << endl;

        // Recursively print children
        int i = 0;
        for (auto& pair : children) {
            cout << string(level * 2, ' ') << (i == children.size() - 1 ? "└─ " : "├─ ");
            cout << "Child " << pair.first << ": ";
            pair.second->printTrie(level + 1);
            i++;
        }
    }

    void addNode(int n,Trie* root,int bit){
        if(bit==-1){
            root->end=true;
            root->count=1;
            return;
        }

        int val=(n>>bit)&1;
        if(root->children.find(val)==root->children.end()){
            root->children[val]=new Trie();
        }
        addNode(n,root->children[val],bit-1);
        root->count+=1;
        return;
    }    

    int query(Trie* root,int upperBound,int num,int bitPosition) {
        if(root->end){
            return root->count;
        }
        cout<<upperBound<<endl;
        int val=(num>>bitPosition)&1;
        int msb1=(upperBound>>bitPosition)&1;
        cout<<msb1<<" "<<val<<" "<<bitPosition<<endl;
        int count=0;
        if(root->children.find(1)!=root->children.end()){
            //take 1
            int msb2=val^1;
            if(msb2==msb1){
                count+=query(root->children[1],upperBound,num,bitPosition-1);
            } else if (msb2>msb1) {
                return 0;
            } 
            return root->count;
        }

        if(root->children.find(0)!=root->children.end()){
            //take 0
            int msb2=val^0;
            if(msb2==msb1){
                count+=query(root->children[0],upperBound,num,bitPosition-1);
            } else if (msb2>msb1) {
                return 0;
            } 
            return root->count;
        }
        return count;
    }
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int maxBits=0;
        for(auto n:nums){
            maxBits=max(maxBits,(int)log2(n));
        }
        int ans=0;
        Trie* root= new Trie();
        for(int i=0;i<nums.size();i++){
            int a = root->query(root,high,nums[i],maxBits);
            int b = root->query(root,low-1,nums[i],maxBits);
            ans+=(a-b);
            cout<<a<<" "<<b<<endl;
            root->addNode(nums[i],root,maxBits);
            root->printTrie();
            cout<<endl;
        }
        return ans;
    }
};

/*
0   0   0   1


0   1   0   0 => 5
0   1   0   1 => 4
0   1   1   0 => 7
0   1   1   1 => 6
1   0   0   0 => 9
1   0   0   1 => 8
1   0   1   0 => 11 
1   0   1   1 => 10
1   1   0   0 => 13
1   1   0   1 => 12
1   1   1   0 => 15
1   1   1   1 => 14




0   0   1   0


0   1   0   0 => 6
0   1   0   1 => 7
0   1   1   0 => 4
0   1   1   1 => 5
1   0   0   0 => 10
1   0   0   1 => 11
1   0   1   0 => 8
1   0   1   1 => 9
1   1   0   0 => 14
1   1   0   1 => 15
1   1   1   0 => 12
1   1   1   1 => 13

*/