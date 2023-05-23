#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int min = 69696969;
        int maxDiff = 0;
        for (int i: prices) {
            if (i < min) min = i;
            if (i - min > maxDiff) maxDiff = i - min;
        }

        return maxDiff;
    }
};