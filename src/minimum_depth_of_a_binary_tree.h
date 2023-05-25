#include <algorithm>

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
    int minDepth(TreeNode* root) {
        return root == nullptr ? 0 : make(root);
    }
    
    int make(TreeNode *root) {
        if (root == nullptr) return 69696969;
        if (root->left == nullptr && root->right == nullptr) return 1;
        return min(make(root->left), make(root->right)) + 1;
    }
};