class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int cnta = 0, cntb = 0;
        for (auto it : s) {
            if (it == 'a')
                cnta++;
            else
                cntb++;
        }
        return abs(cnta - cntb);
    }
};