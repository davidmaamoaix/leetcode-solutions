#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int sb[256] = {0};
        int tb[256] = {0};

        for (auto i: s) sb[i]++;
        for (auto i: t) tb[i]++;

        for (int i = 0; i < 256; i++)
            if (sb[i] != tb[i])
                return false;
        
        return true;
    }
};
