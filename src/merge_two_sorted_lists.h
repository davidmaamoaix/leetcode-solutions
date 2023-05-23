struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if (a == nullptr) return b;
        if (b == nullptr) return a;

        if (a->val < b->val) {
            a->next = this->mergeTwoLists(a->next, b);
            return a;
        } else {
            b->next = this->mergeTwoLists(b->next, a);
            return b;
        }
    }
};
