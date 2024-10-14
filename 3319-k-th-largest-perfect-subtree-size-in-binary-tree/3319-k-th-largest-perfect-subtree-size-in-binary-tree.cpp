/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,int> mp;
    int size = 0;
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        auto [cnt,perfect] = solve(root,k);

        if(cnt>0 && perfect){
            mp[cnt]++;
            size++;
        }

        processMap(mp,size,k);
        if(size!=k){
            return -1;
        }
        return mp.begin()->first;
    }

    pair<int,bool> solve(TreeNode* root,int& k){
        if(!root){
            return {0,true};
        }

        auto [cntL,perfectL] = solve(root->left,k);
        auto [cntR,perfectR] = solve(root->right,k);
        if(cntL>0 && perfectL) {
            mp[cntL]++;
            size++;
        }
        if(cntR>0 && perfectR){
            mp[cntR]++;
            size++;
        }

        processMap(mp,size,k);
        if(cntL==cntR && perfectL && perfectR){
            return {cntL+cntR+1,true};
        } 
        return {max(cntL,cntR),false};
    }

    void processMap(map<int,int>& mp,int& size,int k){
        while(size>k){
            auto [num,count]=*mp.begin();
            if(count==1){
                mp.erase(num);
            } else {
                mp[num]--;
            }
            size--;
        }
    }
};