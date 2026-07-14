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
    void reorderList(ListNode* head) {
        if (!head) return;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = slow->next;
        slow->next = nullptr;
        // cout << secondHalf->val << endl;

        // reverse second half
        ListNode* prev = nullptr;
        while (secondHalf != nullptr) {
            ListNode* currentElem = secondHalf;
            secondHalf = secondHalf->next;

            currentElem->next = prev;
            prev = currentElem;
        }

        // while(head != nullptr){
        //     cout << head->val << " ";
        //     head = head->next;
        // }

        // cout << endl;

        // while(prev != nullptr){
        //     cout << prev->val << " ";
        //     prev = prev->next;
        // }

        ListNode* l1 = head;
        ListNode* l2 = prev; 

        while (l1 and l2) {
            ListNode* next1 = l1->next;
            ListNode* next2 = l2->next;

            l1->next = l2;   
            l2->next = next1; 

            l1 = next1;
            l2 = next2;
        }
    }
};
