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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        // find length
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // adjust k
        k = k % length;
        if (k == 0)
            return head;

        // move temp (length - k - 1) steps
        ListNode* temp = head;
        for (int i = 0; i < length - k - 1; i++) {
            temp = temp->next;
        }

        // use your temp1/temp2 idea
        ListNode* temp1 = temp->next;
        ListNode* temp2 = temp1;

        temp->next = NULL;
        while (tail->next != NULL) { // tail already last node, loop not needed
            tail = tail->next;
        }
        tail->next = head;

        return temp2;
    }
};
