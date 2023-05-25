struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int t) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr) return t == root->val;
        int res = t - root->val;
        return hasPathSum(root->left, res) || hasPathSum(root->right, res);
    }
};
