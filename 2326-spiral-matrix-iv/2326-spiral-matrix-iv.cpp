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
        vector<vector<int>> ans(m,vector<int>(n,-1));
        vector<vector<int>> dir={ {0,1}, {1,0}, {0,-1}, {-1,0} };
        ListNode* ptr=head;
        int row=0;
        int col=0;
        int index=0;
        while(ptr){
            while(ptr && row>=0 && row<m && col>=0 && col<n && ans[row][col]==-1){
                ans[row][col]=ptr->val;
                row+=dir[index][0];
                col+=dir[index][1];
                ptr=ptr->next;
            }
            row-=dir[index][0];
            col-=dir[index][1];
            index=(index+1)%4;
            row+=dir[index][0];
            col+=dir[index][1];
        }
        return ans;
    }
};