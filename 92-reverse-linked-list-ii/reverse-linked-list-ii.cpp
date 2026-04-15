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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp) {
            ListNode* nextPtr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextPtr;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        for (int i = 1; i < left; i++) {
            prev = curr;
            curr = curr->next;
        }
        ListNode* start = curr;
        ListNode* end = curr;
        for (int i = left; i < right; i++) {
            end = end->next;
        }
        ListNode* nextPart = end->next;
        end->next = NULL;
        ListNode* newHead = reverseList(start);
        if (prev)
            prev->next = newHead;
        else
            head = newHead;
        start->next = nextPart;
        return head;
    }
};