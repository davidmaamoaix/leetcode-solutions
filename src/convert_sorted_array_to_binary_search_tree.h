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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return make(nums, 0, nums.size());
    }
    
    TreeNode *make(vector<int> &nums, int a, int b) {
        if (a == b) return nullptr;
        int mid = (a + b) >> 1;
        return new TreeNode(nums[mid], make(nums, a, mid), make(nums, mid + 1, b));
    }
};