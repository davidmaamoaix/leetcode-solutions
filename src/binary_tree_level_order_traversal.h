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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        
        make(root, res, 0);
        
        if (!res.empty() && res[res.size() - 1].empty()) res.pop_back();
        return res;
    }
    
    void make(TreeNode *root, vector<vector<int>>& res, int layer) {
        if (res.size() == layer) res.push_back({});
        if (root == nullptr) return;
        res[layer].push_back(root->val);
        
        make(root->left, res, layer + 1);
        make(root->right, res, layer + 1);
    }
};
