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
    ListNode* merge(ListNode* l, ListNode* r) {
        if (!l) {
            return r;
        } if (!r) {
            return l;
        }
        ListNode* head;
        if (l->val < r->val) {
            head = l;
            l = l->next;
        } else {
            head = r;
            r = r->next;
        }
        ListNode* tmp = head;
        while (l && r) {
            if (l->val < r->val) {
                tmp->next = l;
                l = l->next;
            } else {
                tmp->next = r;
                r = r->next;
            }
            tmp = tmp->next;
        }
        if (l) {
            tmp->next = l;
        }
        if (r) {
            tmp->next = r;
        }
        return head;
    }

    ListNode* mergeRange(vector<ListNode*>& lists, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        if (l == r) {
            return lists[l];
        }
        int mid = l + (r - l) / 2;
        ListNode* left = mergeRange(lists, l, mid);
        ListNode* right = mergeRange(lists, mid + 1, r);
        return merge(left, right);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        return mergeRange(lists, 0, n - 1);
    }
};
