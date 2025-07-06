class Node {
public:
    int val;
    int count;

    Node() {
        val = -1;
        count = 0;
    }

    Node(int value, int cnt) {
        val = value;
        count = cnt;
    }
};


class TreeNodes {
public:
    TreeNodes* left;
    TreeNodes* right;
    int leftIndex;
    int rightIndex;
    Node node;

    TreeNodes(int lIndex, int rIndex) {
        left = NULL;
        right = NULL;
        leftIndex = lIndex;
        rightIndex = rIndex;
        node = Node();
    }

    void constructTree(TreeNodes* root, vector<int>& arr) {
        if (root->leftIndex == root->rightIndex) {
            root->node.val = arr[root->leftIndex];
            root->node.count = 1;
            return;
        }

        int mid = (root->leftIndex + root->rightIndex) / 2;
        root->left = new TreeNodes(root->leftIndex, mid);
        root->right = new TreeNodes(mid + 1, root->rightIndex);
        constructTree(root->left, arr);
        constructTree(root->right, arr);

        root->node = mergeNodes(root->left->node, root->right->node);
    }

    Node mergeNodes(Node leftNode, Node rightNode) {
        if (leftNode.val == rightNode.val) {
            return {leftNode.val, leftNode.count + rightNode.count};
        }
        if (leftNode.count > rightNode.count) {
            return {leftNode.val, leftNode.count - rightNode.count};
        } else {
            return {rightNode.val, rightNode.count - leftNode.count};
        }
    }

    Node query(TreeNodes* root, int l, int r) {
        if (root->leftIndex > r || root->rightIndex < l) {
            return Node();
        }

        if (root->leftIndex >= l && root->rightIndex <= r) {
            return root->node; 
        }

        Node leftResult = query(root->left, l, r);
        Node rightResult = query(root->right, l, r);
        return mergeNodes(leftResult, rightResult);
    }
};

class MajorityChecker {
public:
    TreeNodes* root;
    vector<int> arr;

    MajorityChecker(vector<int>& arr) {
        this->arr = arr;
        root = new TreeNodes(0, arr.size() - 1);
        root->constructTree(root, arr);
    }

    int query(int left, int right, int threshold) {
        Node candidate = root->query(root, left, right);

        if (candidate.val == -1) {
            return -1; 
        }

        int actualCount = 0;
        for (int i = left; i <= right; i++) {
            if (arr[i] == candidate.val) {
                actualCount++;
            }
        }

        return actualCount >= threshold ? candidate.val : -1;
    }
};
