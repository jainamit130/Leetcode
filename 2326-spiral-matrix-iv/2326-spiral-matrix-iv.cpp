/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> dir={ {0,1,n+1}, {1,0,m-1}, {0,-1,n-1}, {-1,0,m-2} };
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int index = 0;
        int row=0,col=0;
        int c=0;
        ListNode* ptr=head;
        while(ptr){
            if(index==0){
                if(c%2==0){
                    dir[index][2]-=2;
                } else {
                    dir[index][2]-=1;
                }
                c++;
            }
            int count = dir[index][2];
            int colDir = dir[index][1];
            int rowDir = dir[index][0];
            while(ptr && count>0){
                ans[row][col]=ptr->val;
                row=row+rowDir;
                col=col+colDir;
                ptr=ptr->next;
                count--;
            }
            if(index!=0){
                dir[index][2]-=2;
            }
            index=(index+1)%4;
        }
        return ans;
    }
};