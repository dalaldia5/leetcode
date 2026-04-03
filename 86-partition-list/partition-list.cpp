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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        vector<int> lesser;
        vector<int> greater;
        while (temp) {
            if (temp->val < x) {
                lesser.push_back(temp->val);
            } 
            else {
                greater.push_back(temp->val);
            }
            temp = temp->next; 
        }
        temp = head;
        for (int val : lesser) {
            temp->val = val;
            temp = temp->next;
        }
        for (int val : greater) {
            temp->val = val;
            temp = temp->next;
        }
        return head;
    }
};