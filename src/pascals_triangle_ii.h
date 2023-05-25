#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec;
        for (int i = 0; i <= rowIndex; i++) vec.push_back(comb(rowIndex, i));
        return vec;
    }
    
    int comb(int n, int k) {
        if (k > n) return 0;
        if (k * 2 > n) k = n-k;
        if (k == 0) return 1;

        long long int result = n;
        for(int i = 2; i <= k; ++i) {
            result *= (n-i+1);
            result /= i;
        }
        return (int) result;
    }
};
