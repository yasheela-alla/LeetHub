class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy; 

        while (curr->next && curr->next->next) {
            if (curr->next->val == curr->next->next->val) {
                int duplicateVal = curr->next->val;
                while (curr->next && curr->next->val == duplicateVal) {
                    ListNode* temp = curr->next;
                    curr->next = curr->next->next;
                    delete temp;
                }
            } else {
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};