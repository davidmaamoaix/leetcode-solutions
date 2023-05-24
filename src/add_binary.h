#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        if (a.size() < b.size()) a += string(b.size() - a.size(), '0');
        if (a.size() > b.size()) b += string(a.size() - b.size(), '0');
        
        string out;
        int inc = 0;
        for (int i = 0; i < a.size(); i++) {
            int sum = a[i] - 48 + b[i] - 48 + inc;
            out += "01"[sum & 1];
            inc = (sum & 2) >> 1;
        }
        
        if (inc) out += "1";
        reverse(out.begin(), out.end());
        return out;
    }
};
