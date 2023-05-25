#include <vector>

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        make(root, vec);
        return vec;
    }
    
    void make(TreeNode *n, vector<int> &ref) {
        if (n == nullptr) return;
        make(n->left, ref);
        ref.push_back(n->val);
        make(n->right, ref);
    }
};
