class Solution {
public:
    void dfs(Node* node, Node* cloneNode, unordered_map<Node*, Node*>& mpp) {
        for (Node* n : node->neighbors) {
            if (mpp.find(n) == mpp.end()) {
                Node* clone = new Node(n->val);
                mpp[n] = clone;
                cloneNode->neighbors.push_back(clone);
                dfs(n, clone, mpp);
            } else {
                cloneNode->neighbors.push_back(mpp[n]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if (!node)
            return NULL;
        unordered_map<Node*, Node*> mpp;
        mpp.clear();
        Node* cloneNode = new Node(node->val);
        mpp[node] = cloneNode;
        dfs(node, cloneNode, mpp);
        return cloneNode;
    }
};