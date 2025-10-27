/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertCopyInBetween(Node* head) {
        Node* temp = head;
        while (temp) {
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = nextElement;
        }
    }
    void connectRandomPointers(Node* head) {
        Node* temp = head;
        while (temp) {
            Node* copyNode = temp->next;
            if (temp->random)
                copyNode->random = temp->random->next;
            else
                copyNode->random = nullptr;
            temp = temp->next->next;
        }
    }
    Node* getDeepCopy(Node* head) {
        Node* temp = head;
        Node* dNode = new Node(-1);
        Node* res = dNode;
        while (temp) {
            res->next = temp->next;
            res = res->next;
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dNode->next;
    }
    Node* copyRandomList(Node* head) {
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopy(head);
    }
};