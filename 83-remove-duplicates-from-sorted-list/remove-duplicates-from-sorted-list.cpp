// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         // base case
//         if(!head || !head->next) return head;
//         // traverse 
//         ListNode* curr = head;
//         while(curr && curr->next){
//             if(curr->val == curr->next->val){
//                 ListNode* nextNode = curr->next->next;
//                 delete curr->next;
//                 curr->next = nextNode;
//             } else {
//                 curr = curr->next;
//             }
//         }
//         return head;
//     }
// };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        set<int> seen;
        ListNode* newHead = nullptr;
        ListNode* newTail = nullptr;

        while (head) {
            if (seen.find(head->val) == seen.end()) {
                seen.insert(head->val);
                if (!newHead) {
                    newHead = head;
                    newTail = head;
                } else {
                    newTail->next = head;
                    newTail = head;
                }
            }
            head = head->next;
        }

        if (newTail) {
            newTail->next = nullptr;
        }

        return newHead;
    }
};