#include <unordered_map>

using namespace std;

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
    bool isBalanced(TreeNode* root) {
        unordered_map<TreeNode *, int> path;
        init(root, path);
        return balanced(root, path);
    }
    
    int init(TreeNode *root, unordered_map<TreeNode *, int> &d) {
        if (root == nullptr) return 0;
        int len = max(init(root->left, d), init(root->right, d)) + 1;
        d[root] = len;
        return len;
    }
    
    bool balanced(TreeNode *root, unordered_map<TreeNode *, int> &d) {
        if (root == nullptr) return true;
        return balanced(root->left, d)
            && balanced(root->right, d)
            && abs(d[root->left] - d[root->right]) <= 1;
    }
};