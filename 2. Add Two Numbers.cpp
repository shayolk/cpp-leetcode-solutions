/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    int value(ListNode* l) {
        if (!l) {
            return 0;
        }
        return l->val;
    }

    ListNode* add(ListNode* l1, ListNode* l2, int carry) {
        if (!l1) {
            if (!l2) {
                if (!carry) {
                    return l1;
                }
                return new ListNode(carry);
            }
            return add(l2, l1, carry);
        }
        int val = value(l1) + value(l2) + carry;
        l1->val = val%10;
        l1->next = add(l1->next, l2 ? l2->next : l2, val/10);
        return l1;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
};
