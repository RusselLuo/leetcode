struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *mid = head->next;
        if (!mid->next) {
            if (head->val > mid->val) {
                mid->next = head;
                head->next = nullptr;
                return mid;
            }
            return head;
        }
        ListNode *end = head->next->next;
        while (end && end->next) {
            mid = mid->next;
            end = end->next->next;
        }
        auto *secondHead = mid->next;
        mid->next = nullptr;
        // cout<<secondHead->val<<endl;
        return merge(sortList(head), sortList(secondHead));
    }
    ListNode *merge(ListNode *head, ListNode *mid) {
        ListNode *merged = nullptr;
        ListNode *curr = nullptr;
        // cout<<head->val<<","<<mid->val;
        while (head && mid) {
            if (head->val < mid->val) {
                if (!merged) {
                    curr = merged = head;
                } else {
                    curr->next = head;
                    curr = curr->next;
                }
                head = head->next;
            } else {
                if (!merged) {
                    curr = merged = mid;
                } else {
                    curr->next = mid;
                    curr = curr->next;
                }
                mid = mid->next;
            }
        }
        if (!head) {
            curr->next = mid;
        } else if (!mid) {
            curr->next = head;
        }
        return merged;
    }
};