class Solution {
public:
    unordered_map<string, bool> t;

    bool fun(string curr, unordered_map<string, vector<char>>& mpp, int idx,
             string above) {
        // Base case: agar current row me sirf 1 block bacha
        // matlab pyramid successfully ban gaya
        if (curr.size() == 1)
            return true;

        string key = curr + "_" + to_string(idx) + "_" + above;

        if (t.count(key))
            return t[key];

        // Jab current row ke saare adjacent pairs process ho gaye
        // toh upar wali row (above) ke liye recursion call
        if (idx == curr.size() - 1)
            return t[key] = fun(above, mpp, 0, "");

        // Current row ke do adjacent blocks ka pair
        string pair = curr.substr(idx, 2);

        // Agar is pair ke liye koi valid upper block hi nahi
        // toh is path se pyramid possible nahi
        if (mpp.find(pair) == mpp.end())
            return t[key] = false;

        // Har possible upper block try karo (backtracking)
        for (char& ch : mpp[pair]) {
            above.push_back(ch); // DO: upar wali row me block add karo

            // EXPLORE: next index ke liye recursion
            if (fun(curr, mpp, idx + 1, above) == true)
                return t[key] = true;

            above.pop_back(); // UNDO: agar fail hua toh last block hata do
        }

        // Agar koi bhi option se pyramid nahi bana
        return t[key] = false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mpp;

        // Allowed patterns ko map me store kar rahe
        // if 'ABC', 'ABD' given in allowed then:
        // "AB" -> {'C', 'D'} type mapping
        for (auto& pattern : allowed) {
            mpp[pattern.substr(0, 2)].push_back(pattern[2]);
        }

        // Bottom se start karke recursion call
        return fun(bottom, mpp, 0, "");
    }
};
