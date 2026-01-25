/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return NULL;
        }
        queue<Node*> q;
        q.push(root);
        // level ke end ko mark
        q.push(NULL);
        // prev: same level ke previous node ko store karna
        Node* prev = NULL;
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            // NULL -> ek level over
            if (curr == NULL) {
                if (q.size() == 0) {
                    break;
                }
                // Next level ke end ko mark krdo
                q.push(NULL);
            } else {
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
                // Agar prev NULL nahi hai-> same level ka koi previous node
                // exist krta h
                if (prev != NULL) {
                    prev->next = curr;
                }
            }
            prev = curr;
        }
        return root;
    }
};