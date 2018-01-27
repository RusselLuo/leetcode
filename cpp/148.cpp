struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next){
            return head;
        }
        ListNode *mid = head->next;
        ListNode *end = head->next->next;
        if(!end){
            if(head->val>mid->val){
                mid->next = head;
                head->next = nullptr;
                return mid;
            }
            return head;
        }
        //iterate the linked list, make end step twice faster than mid
        while(end&&end->next){
            mid = mid->next;
            end = end->next->next;
        }
        ListNode *secondHead = mid->next;
        mid->next = nullptr;
        return merge(sortList(head),sortList(secondHead));
    }
    ListNode* merge(ListNode *first, ListNode *second){
        ListNode *merged = nullptr;
        ListNode *curr = merged;
        //iterate both sorted linked list, append the smaller node to the merged linked list.
        while(second&&first){
            if(first->val<second->val){
                if(!merged){
                    curr = merged = first;
                }else{
                    curr->next = first;
                    curr = curr->next;
                }
                first = first->next;
            }else{
                if(!merged){
                    curr = merged = second;
                }else{
                    curr->next = second;
                    curr = curr->next;
                }
                second = second->next;
            }
        }
        if(!first){
            curr->next = second;
        }else{
            curr->next = first;
        }
        return merged;
    }
};