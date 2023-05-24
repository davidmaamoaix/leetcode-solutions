#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0, l = 0, r = height.size() - 1;
        int lMax = height[l], rMax = height[r];
        
        while (l < r) {
            if (lMax < rMax) {
                l++;
                if (height[l] > lMax) lMax = height[l];
                else sum += lMax - height[l];
            } else {
                r--;
                if (height[r] > rMax) rMax = height[r];
                else sum += rMax - height[r];
            }
        }
        
        return sum;
    }
};
