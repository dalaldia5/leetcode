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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        
        // Dummy node for result
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (true) {
            int minIndex = -1;

            // Find the list with smallest current node
            for (int i = 0; i < k; i++) {
                if (lists[i] != NULL) {
                    if (minIndex == -1 || lists[i]->val < lists[minIndex]->val) {
                        minIndex = i;
                    }
                }
            }

            // If all lists are exhausted
            if (minIndex == -1) break;

            // Add smallest node to result
            tail->next = lists[minIndex];
            tail = tail->next;

            // Move that list forward
            lists[minIndex] = lists[minIndex]->next;
        }

        return dummy->next;
    }
};