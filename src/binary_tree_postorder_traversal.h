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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        run(root, vec);
        return vec;
    }
    
    void run(TreeNode *r, vector<int> &vec) {
        if (r == nullptr) return;
        run(r->left, vec);
        run(r->right, vec);
        vec.push_back(r->val);
    }
};
