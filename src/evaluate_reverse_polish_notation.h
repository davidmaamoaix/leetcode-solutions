#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> eval;
        
        for (auto s: tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = eval.top(); eval.pop();
                int a = eval.top(); eval.pop();
                
                if (s == "+") eval.push(a + b);
                if (s == "-") eval.push(a - b);
                if (s == "*") eval.push(a * b);
                if (s == "/") eval.push(a / b);
            } else {
                eval.push(stoi(s));
            }
        }
        
        return eval.top();
    }
};
