#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int mask = image[sr][sc];
        int h = image.size(), w = image[0].size();

        set<pair<int, int>> v;
        queue<pair<int, int>> q;
        q.push({sr, sc});

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            int r = curr.first, c = curr.second;
            q.pop();
            
            if (image[r][c] != mask || v.find({r, c}) != v.end()) continue;
            v.insert({r, c});

            image[r][c] = color;
            if (r > 0) q.push({r - 1, c});
            if (r < h - 1) q.push({r + 1, c});
            if (c > 0) q.push({r, c - 1});
            if (c < w - 1) q.push({r, c + 1});
        }

        return image;
    }
};
