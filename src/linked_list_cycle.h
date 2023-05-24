#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> v;
        
        if (head == nullptr) return false;
        while (head != nullptr) {
            if (v.find(head) != v.end()) return true;
            v.insert(head);
            
            head = head->next;
        }
        
        return false;
    }
};
