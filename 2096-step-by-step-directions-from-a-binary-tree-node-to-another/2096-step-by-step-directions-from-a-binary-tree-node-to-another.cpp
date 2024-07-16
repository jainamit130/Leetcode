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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string srcDicrections="";
        int srcDepth=0;
        string directions="";
        int depth=0;
        directionsPlease(root,startValue,directions,depth,srcDicrections,srcDepth);

        string destDicrections="";
        int destDepth=0;
        directions="";
        depth=0;
        directionsPlease(root,destValue,directions,depth,destDicrections,destDepth);

        string ans="";
        int i=0;
        while(i<min(srcDicrections.length(),destDicrections.length())){
            if(srcDicrections[i]!=destDicrections[i]){
                break;
            }
            i++;
        }

        if(i<srcDicrections.length() && i<destDicrections.length()){
            int t=0;
            while(i<srcDicrections.length()){
                ans+='U';
                i++;
                t++;
            }

            int j=i-t;
            while(j<destDicrections.length()){
                ans+=destDicrections[j];
                j++;
            }
            return ans;
        }

        if(i<srcDicrections.length()){
            while(i<srcDicrections.length()){
                ans+='U';
                i++;
            }
            return ans;
        }

        if(i<destDicrections.length()){
            while(i<destDicrections.length()){
                ans+=destDicrections[i];
                i++;
            }
            return ans;
        }

        return ans;
    }

    void directionsPlease(TreeNode* root,int searchValue,string& curr,int& depth,string& directions,int& deep){
        if(!root){
            return;
        }

        if(root->val==searchValue){
            directions=curr;
            deep=depth;
            return;
        }

        curr+='L';
        depth+=1;
        directionsPlease(root->left,searchValue,curr,depth,directions,deep);
        curr.pop_back();
        curr+='R';
        directionsPlease(root->right,searchValue,curr,depth,directions,deep);
        curr.pop_back();
        depth-=1;
        return;
    }
};