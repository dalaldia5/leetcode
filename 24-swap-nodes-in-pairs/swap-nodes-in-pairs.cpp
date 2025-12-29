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
    ListNode* swapPairs(ListNode* head) {

        // Agar LL empty hai ya sirf 1 node hai toh swap possible nhi
        if (head == NULL || head->next == NULL)
            return head;

        // First swap ke baad second node hi new head banega
        ListNode* newHead = head->next;

        // temp current pair ke first node ko point karega
        ListNode* temp = head;

        // prevTail pichhle swapped pair ke last node ko yaad rakhega
        ListNode* prevTail = NULL;

        // Jab tak 2 nodes available hain, tab tak swap karte raho
        while (temp != NULL && temp->next != NULL) {

            // prev = current pair ka first node
            ListNode* prev = temp;

            // curr = current pair ka second node
            ListNode* curr = temp->next;

            // first node ko next pair se connect karo
            prev->next = curr->next;

            // second node ko first ke aage laga do (swap)
            curr->next = prev;

            // Agar pehle koi pair swap ho chuka hai,
            // toh uske tail ko current swapped pair se jodo
            if (prevTail != NULL)
                prevTail->next = curr;

            // Ab current pair ka first node hi tail ban gaya
            prevTail = prev;

            // temp ko next pair ke start par le jao
            temp = prev->next;
        }

        // Final swapped list ka head return karo
        return newHead;
    }
};
