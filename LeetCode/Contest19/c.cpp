class Solution {
public:
    void find(TreeNode* currNode, int depth, vector <int>& vi) {
        vi[depth] = max(vi[depth], currNode->val);
        if (currNode->left != nullptr) find(currNode->left, depth + 1, vi);
        if (currNode->right != nullptr) find(currNode->right, depth + 1, vi);
    }
    int recurse(TreeNode* currNode) {
        int l = 0, r = 0;
        if (currNode->left != nullptr) l = recurse(currNode->left) + 1;
        if (currNode->right != nullptr) r = recurse(currNode->right) + 1;
        return max(l, r);
    }
    vector<int> largestValues(TreeNode* root) {
        if(root == nullptr) {
            vector <int> vi;
            return vi;
        }
        int mx = recurse(root);
        vector <int> vi(mx + 1, 1 << 31);
        find(root, 0, vi);
        return vi;
    }
};
