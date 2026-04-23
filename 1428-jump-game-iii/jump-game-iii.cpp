class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (arr[i] == 0)
                return true;

            int forward = i + arr[i];
            int backward = i - arr[i];

            if (forward < n && !visited[forward]) {
                q.push(forward);
                visited[forward] = true;
            }

            if (backward >= 0 && !visited[backward]) {
                q.push(backward);
                visited[backward] = true;
            }
        }

        return false;
    }
};