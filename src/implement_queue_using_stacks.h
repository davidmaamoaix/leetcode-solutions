#include <stack>

using namespace std;

class MyQueue {   
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        b.push(x);
    }
    
    int pop() {
        if (a.empty()) {
            while (!b.empty()) {
                a.push(b.top());
                b.pop();
            }
        }

        int top = a.top();
        a.pop();
        return top;
    }
    
    int peek() {
        if (a.empty()) {
            while (!b.empty()) {
                a.push(b.top());
                b.pop();
            }
        }
        
        return a.top();
    }
    
    bool empty() {
        return a.empty() && b.empty();
    }
    
private:
    stack<int> a;
    stack<int> b;
};
