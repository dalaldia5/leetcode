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
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp2 = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        while (temp2) {
            ListNode* nextPtr = temp2->next;
            temp2->next = prev;
            prev = temp2;
            temp2 = nextPtr;
        }
        ListNode* temp = head; // 1,2
        ListNode* nextPtr = temp->next;
        // temp -> 1 2 3 
        // prev -> 5 4 
        while (prev) {
            ListNode* nextPtr=temp->next;
            ListNode* afterPtr=prev->next;
            temp->next=prev;
            prev->next=nextPtr;
            temp=nextPtr;
            prev=afterPtr;
        }
    }
};