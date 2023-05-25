#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
        unordered_set<ListNode *> m;
        while (a != nullptr) {
            m.insert(a);
            a = a->next;
        }
        
        while (b != nullptr) {
            if (m.find(b) != m.end()) return b;
            b = b->next;
        }
        
        return nullptr;
    }
};