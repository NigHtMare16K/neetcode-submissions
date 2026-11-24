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
        if (head == NULL) return;

        while (head != NULL && head->next != NULL && head->next->next != NULL) {
            ListNode* prev = NULL;
            ListNode* tail = head;
            ListNode* next1 = head->next;

            while (tail->next != NULL) {
                prev = tail;
                tail = tail->next;
            }

            head->next = tail;
            prev->next = NULL;
            tail->next = next1;
            head = next1;
        }
    }
};
