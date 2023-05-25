struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return rec(l1, l2, 0);
    }
    
    ListNode *rec(ListNode *a, ListNode *b, int carry) {
        if (a == nullptr && b == nullptr) {
            return carry ? new ListNode(1) : nullptr;
        }
        
        int sum = carry;
        if (a != nullptr) sum += a->val;
        if (b != nullptr) sum += b->val;
        
        ListNode *out = new ListNode(sum % 10);
        out->next = rec(a == nullptr ? a : a->next, b == nullptr ? b : b->next, sum / 10);
        
        return out;
    }
};
