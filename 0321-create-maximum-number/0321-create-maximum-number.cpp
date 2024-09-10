class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        for (int i = 0; i <= k; i++) {
            vector<int> a = mostCompetitive(nums1, i);
            for (int m = 0; m < a.size(); m++) {
                cout << a[m] << " ";
            }
            cout << endl;
            vector<int> b = mostCompetitive(nums2, k - i);
            for (int m = 0; m < b.size(); m++) {
                cout << b[m] << " ";
            }
            cout << endl;
            vector<int> subAns = merge(a, b);
            if (subAns.size() == k)
                ans = max(subAns, ans);
        }
        return ans;
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        int i = 0, j = 0;
        vector<int> ans;
        while (i < a.size() && j < b.size()) {
            if (a[i] > b[j]) {
                ans.push_back(a[i]);
                i++;
            } else if (a[i] < b[j]) {
                ans.push_back(b[j]);
                j++;
            } else {
                int k = i, l = j;
                while (k < a.size() && l < b.size() && a[k] == b[l]) {
                    k++;
                    l++;
                }
                
                if(k==a.size()) ans.push_back(a[i]),i++;
                else if(k<a.size() && a[k]>b[l]) ans.push_back(a[i]),i++;
                else ans.push_back(b[j]),j++;
            }
        }

        while (i < a.size()) {
            ans.push_back(a[i]);
            i++;
        }

        while (j < b.size()) {
            ans.push_back(b[j]);
            j++;
        }

        return ans;
    }

    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        int elementsToRemove = nums.size() - k;
        for (int i = 0; i < nums.size(); i++) {
            while (!ans.empty() && elementsToRemove > 0 &&
                   ans.back() < nums[i]) {
                ans.pop_back();
                elementsToRemove--;
            }
            ans.push_back(nums[i]);
        }
        while (elementsToRemove > 0) {
            ans.pop_back();
            elementsToRemove--;
        }
        return ans;
    }
};

/*





*/