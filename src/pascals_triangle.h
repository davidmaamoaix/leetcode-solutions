#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        for (int i = 0; i < numRows; i++) addRow(i, vec);
        return vec;
    }
    
    void addRow(int row, vector<vector<int>> &ref) {
        vector<int> v;
        if (row != 0) v.push_back(1);
        for (int i = 0; i < row - 1; i++) {
            v.push_back(ref[row - 1][i] + ref[row - 1][i + 1]);
        }
        v.push_back(1);
        
        ref.push_back(v);
    }
};
