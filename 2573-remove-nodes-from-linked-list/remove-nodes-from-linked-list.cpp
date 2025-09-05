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
    ListNode* removeNodes(ListNode* head) {
        // Edge case: if list is empty or has only one node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // ---- Step 1: Reverse the linked list ----
        // After reversing, "greater values to the right"
        // become "greater values to the left" which is easier to handle
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next; // Save next node
            curr->next = prev;           // Reverse the pointer
            prev = curr;                 // Move prev forward
            curr = next;                 // Move curr forward
        }

        // Now 'prev' points to the head of reversed list

        // ---- Step 2: Traverse reversed list and keep only nodes
        // that are >= max value seen so far ----
        curr = prev->next;        // Start from 2nd node
        prev->next = nullptr;     // Break link (we'll rebuild valid list)
        ListNode* newHead = prev; // This will be the head of filtered list

        while (curr != nullptr) {
            ListNode* temp = curr->next;

            // If current node's value >= last kept node's value,
            // then this node should also be kept
            if (curr->val >= newHead->val) {
                curr->next = newHead; // Insert at front
                newHead = curr;       // Move head to current
            }

            // Move to next node
            curr = temp;
        }

        // ---- Step 3: 'newHead' is already in correct order ----
        // Because we inserted nodes in decreasing order while traversing
        // reversed list

        return newHead;
    }
};
