class Solution {
public:
    int val, res;
    bool found = false;
    void find(TreeNode* currNode, int depth) {
        if (found) return;
        if (depth == val) {
            found = true;
            res = currNode->val;
            return;
        }
        if (currNode->left != nullptr) find(currNode->left, depth + 1);
        if (currNode->right != nullptr) find(currNode->right, depth + 1);
    }
    int recurse(TreeNode* currNode) {
        int l = 0, r = 0;
        if (currNode->left != nullptr) l = recurse(currNode->left) + 1;
        if (currNode->right != nullptr) r = recurse(currNode->right) + 1;
        return max(l, r);
    }
    int findBottomLeftValue(TreeNode* root) {
        int mx = recurse(root);
        val = mx;
        find(root, 0);
        return res;
    }
};
