class Solution {
public:
    int minimumDeletions(string word, int k) {
        // Step 1: Count the frequency of each character
        unordered_map<char, int> mpp;
        for (auto ch : word) {
            mpp[ch]++;
        }

        // Step 2: Store all character frequencies in a vector
        vector<int> freq;
        for (auto x : mpp) {
            freq.push_back(x.second);
        }

        // Step 3: Sort the frequency list
        // Sorting helps us to compare frequencies easily from smallest to
        // largest
        sort(freq.begin(), freq.end());

        // The maximum frequency of any character
        int mx = freq.back();

        // Initialize answer with a large number
        int ans = INT_MAX;

        // Step 4: Try making all character frequencies fall within [i, i + k]
        // where 'i' is the minimum frequency we target in this iteration
        for (int i = 1; i <= mx; i++) {
            int deletions = 0;

            // Step 5: For each character frequency
            for (int f : freq) {
                if (f > i + k) {
                    // Case 1: Frequency too high → delete extra characters
                    deletions += f - (i + k);
                } else if (f < i) {
                    // Case 2: Frequency too low → delete all occurrences (can't
                    // increase it)
                    deletions += f;
                }
                // Case 3: If f is within [i, i + k], do nothing
            }

            // Step 6: Track the minimum number of deletions among all possible
            // targets
            ans = min(ans, deletions);
        }

        // Step 7: Return the minimum deletions needed
        return ans;
    }
};
