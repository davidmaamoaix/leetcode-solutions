#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) l = mid + 1;
            else if (nums[mid] > target) r = mid - 1;
        }
        
        return nums[l] == target ? l : -1;
    }
};