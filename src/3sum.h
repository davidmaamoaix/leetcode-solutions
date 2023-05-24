#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2;) {
            int rest = 0 - nums[i];
            
            int l = i + 1;
            int r = nums.size() - 1;
            
            while (l < r) {
                while (r > l && nums[l] + nums[r] > rest) r--;
                while (r > l && nums[l] + nums[r] < rest) l++;

                if (l != r && nums[l] + nums[r] == rest) {
                    out.push_back({nums[i], nums[l], nums[r]});
                    
                    int currL = nums[l];
                    while (r > l && nums[l] == currL) l++;
                    int currR = nums[r];
                    while (r > l && nums[r] == currR) r--;
                }
            }
            
            int currI = nums[i];
            while (i < nums.size() - 2 && currI == nums[i]) i++;
        }
        
        return out;
    }
};
