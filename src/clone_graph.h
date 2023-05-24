#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;
        
        unordered_map<Node *, Node *> c;
        queue<Node *> q;
        
        Node *ret = new Node(node->val);
        c[node] = ret;
        for (Node *i: node->neighbors) {
            Node *curr = new Node(i->val);
            c[i] = curr;
            q.push(i);
            ret->neighbors.push_back(curr);
        }
        
        while (!q.empty()) {
            Node *curr = q.front();
            q.pop();
            
            for (Node *i: curr->neighbors) {
                bool newVal = c.find(i) == c.end();
                if (newVal) {
                    c[i] = new Node(i->val);
                    q.push(i);
                }
                
                c[curr]->neighbors.push_back(c[i]);
                
            }
        }
        
        return ret;
    }
};
