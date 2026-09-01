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
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* gcd = new ListNode(__gcd(head->val, head->next->val));
        gcd->next = insertGreatestCommonDivisors(head->next);
        head->next = gcd;
        return head;
    }
};
