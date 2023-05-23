#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string acc;
        for (char i: s) {
            if (97 <= i && i < 97 + 26 || 48 <= i && i < 48 + 10) acc += i;
            if (65 <= i && i < 65 + 26) acc += i + 32;
        }

        for (int i = 0; i < acc.length(); i++) {
            if (acc[i] != acc[acc.length() - 1 - i]) return false;
        }

        return true;
    }
};
