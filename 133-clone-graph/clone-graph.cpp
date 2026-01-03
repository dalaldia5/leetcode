class Solution {
public:
    // DFS function jo original graph ko traverse karke uska clone banata hai
    void dfs(Node* node, Node* cloneNode, unordered_map<Node*, Node*>& mpp) {

        // original node ke saare neighbors par loop
        for (Node* n : node->neighbors) {

            // agar ye neighbor pehle clone nahi hua
            if (mpp.find(n) == mpp.end()) {

                // neighbor ka naya clone node banao
                Node* clone = new Node(n->val);

                // mapping store karo: original -> clone
                mpp[n] = clone;

                // current cloneNode ke neighbors me add karo
                cloneNode->neighbors.push_back(clone);

                // DFS call karo is neighbor ke liye
                dfs(n, clone, mpp);

            } else {
                // agar neighbor already clone ho chuka hai
                // toh directly uska clone add karo (cycle handle ho jaata hai)
                cloneNode->neighbors.push_back(mpp[n]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        // agar graph empty hai
        if (!node)
            return NULL;

        // map jo original node ko uske clone se map karega
        unordered_map<Node*, Node*> mpp;

        // starting node ka clone banao
        Node* cloneNode = new Node(node->val);

        // original start node ko uske clone se map karo
        mpp[node] = cloneNode;

        // DFS se poora graph clone karo
        dfs(node, cloneNode, mpp);

        // cloned graph ka starting node return
        return cloneNode;
    }
};
