class Solution {
public:
    // Function to calculate the improvement (gain)
    // when we add one extra student to a class
    double getGain(int pass, int total) {
        double before = (double)pass / total;
        double after = (double)(pass + 1) / (total + 1);
        return after - before;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Max-heap where each element is:
        // {gain if we add 1 student, {passed, total}}
        priority_queue<pair<double, pair<int, int>>> pq;

        double totalAverage = 0.0;

        // Step 1: Put all classes in heap
        for (auto& c : classes) {
            int pass = c[0];
            int total = c[1];
            totalAverage += (double)pass / total;
            pq.push({getGain(pass, total), {pass, total}});
        }

        // Step 2: Distribute extra students one by one
        while (extraStudents--) {
            auto topClass = pq.top();
            pq.pop();

            int pass = topClass.second.first;
            int total = topClass.second.second;

            // Remove old contribution
            totalAverage -= (double)pass / total;

            // Add new student
            pass++;
            total++;

            // Add new contribution
            totalAverage += (double)pass / total;

            // Push back updated class
            pq.push({getGain(pass, total), {pass, total}});
        }

        // Step 3: Return final average
        return totalAverage / classes.size();
    }
};
