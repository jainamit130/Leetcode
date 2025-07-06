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
    int sum=0;
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        auto [cnt,perfect] = solve(root,k);
        if(perfect && cnt>0){
            sum+=1;
            mp[cnt]++;
            processMap(k);
        }
        if(sum<k){
            return -1;
        }
        return mp.begin()->first;
    }

    pair<int,bool> solve(TreeNode* root,int k){
        if(!root){
            return {0,true};
        }

        auto [cntL,perfectL] = solve(root->left,k);
        auto [cntR,perfectR] = solve(root->right,k);
        if(perfectL && cntL>0){
            sum+=1;
            mp[cntL]++;
        }
        if(perfectR && cntR>0){
            sum+=1;
            mp[cntR]++;
        }

        processMap(k);

        if(perfectL && perfectR && cntL==cntR){
            return {cntL+cntR+1,true};
        }
        return {max(cntL,cntR),false};
    }

    void processMap(int k){
        while(sum>k){
            auto [smallest,count]= *mp.begin();
            if(count==1){
                mp.erase(smallest);
            } else {
                mp[smallest]-=1;
            }
            sum--;
        }
    }
};