class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& cap) {
        int n = p.size();
        vector<pair<int,int>> projects;
        for(int i = 0; i < n; i++) {
            projects.push_back({cap[i], p[i]});
        }
        sort(projects.begin(), projects.end());
        priority_queue<int> maxHeap;
        int i = 0;
        while(k) {
            while(i < n && projects[i].first <= w) {
                maxHeap.push(projects[i].second);
                i++;
            }
            if(maxHeap.empty()) break; // no cap corresponding to initial w
            w += maxHeap.top();
            maxHeap.pop();
            k--;
        }
        
        return w;
    }
};