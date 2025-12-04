class Solution {
public:
    int countCollisions(string dir) {
        int n = dir.size();
        int collision = 0;
        bool accident;
        accident = false;
        for (int i = 1; i < n; i++) {
            if (dir[i] == 'L') {
                if (dir[i - 1] != 'L' || accident) {
                    collision += 1;
                    accident = true;
                }
            }
        }
        accident = false;
        for (int i = n - 2; i >= 0; i--) {
            if (dir[i] == 'R') {
                if (dir[i + 1] != 'R' || accident) {
                    collision += 1;
                    accident = true;
                }
            }
        }
        return collision;
    }
};