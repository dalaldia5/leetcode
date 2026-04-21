class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        vector<int> ans(deck.size(),0);
        sort(deck.begin(), deck.end());
        deque<int> dq;
        for (int i=0; i<deck.size(); i++){
            dq.push_back(i);
        }
        for (auto it: deck){
            int idx=dq.front();
            dq.pop_front();
            ans[idx]=it;
            if (!dq.empty()){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        return ans;
    }
};