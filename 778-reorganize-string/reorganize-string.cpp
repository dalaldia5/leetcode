class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        unordered_map<char, int> mpp;
        for (auto it : s) {
            mpp[it]++;
        }
        // max heap {frequency, character}
        priority_queue<pair<int, char>> pq;
        for (auto it : mpp) {
            if (it.second > (s.size() + 1) / 2) {
                return "";
            }
            pq.push({it.second, it.first});
        }
        while (pq.size() >= 2) {
            auto top1 = pq.top(); 
            pq.pop();
            auto top2 = pq.top(); 
            pq.pop();
            ans += top1.second;
            ans += top2.second;
            if (--top1.first > 0) pq.push(top1);
            if (--top2.first > 0) pq.push(top2);
        }
        if (!pq.empty()) {
            ans += pq.top().second;
        }
        return ans;
    }
};