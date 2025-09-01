class Solution {
public:
    int score(vector<string>& cards, char x) {
        // n = count of cards where x is at position 0 but not both
        // m = count of cards where x is at position 1 but not both
        // k = count of cards where both positions are x
        int n = 0, m = 0, k = 0;

        // Frequency maps
        // a -> counts of the *other character* in cards of form "xY"
        // b -> counts of the *other character* in cards of form "Yx"
        map<int, int> a, b;

        // Step 1: Classify cards based on x's position
        for (auto card : cards) {
            if (card[0] == x && card[1] == x) {
                // Both characters are x, special case
                k++;
            } else if (card[0] == x) {
                // x at first position, track the second character
                a[card[1]]++;
                n++;
            } else if (card[1] == x) {
                // x at second position, track the first character
                b[card[0]]++;
                m++;
            }
        }

        // Step 2: Find the maximum frequency of any character
        // This is important because to maximize pairs,
        // we may have to leave out the most frequent character unpaired.
        int a_max = 0, b_max = 0;
        for (auto& [ch, freq] : a)
            a_max = max(a_max, freq);
        for (auto& [ch, freq] : b)
            b_max = max(b_max, freq);

        // Step 3: Count how many pairs we can form
        int pair1 = 0, pair2 = 0, unpaired = 0;

        // For "xY" type cards:
        // At best, we can form n/2 pairs.
        // But if one character dominates (say all are "xA"),
        // we cannot pair them all, hence we subtract that maximum.
        pair1 = min(n / 2, n - a_max);
        unpaired += n - 2 * pair1; // leftover unpaired cards

        // Similarly for "Yx" type cards:
        pair2 = min(m / 2, m - b_max);
        unpaired += m - 2 * pair2; // leftover unpaired cards

        // Step 4: Add contribution of "xx" cards
        // They can pair with unpaired cards first.
        int ans = pair1 + pair2 + min(unpaired, k);

        // If we still have more "xx" cards left after covering unpaired ones,
        // then they can form pairs among themselves (2 "xx" → 1 extra point).
        if (k > unpaired) {
            ans += min(pair1 + pair2, (k - unpaired) / 2);
        }

        return ans;
    }
};
