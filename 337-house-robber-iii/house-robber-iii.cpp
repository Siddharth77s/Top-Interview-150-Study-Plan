class Solution {
    pair<int, int> dfs(TreeNode* root) { // rob, skip
        if (!root) return { 0, 0 };
        auto [lr, ls] = dfs(root->left);
        auto [rr, rs] = dfs(root->right);
        return { root->val + ls + rs, max(lr, ls) + max(rr, rs) };
    }
public:
    int rob(TreeNode* root) {
        auto [r, s] = dfs(root);
        return max(r, s);
    }
};