class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mpp;
        for (auto it: s1){
            mpp[it]++;
        }
        int k = s1.size();
        for (int i = 0; i <= (int)s2.size() - k; i++){
            unordered_map<char, int> temp = mpp;
            for (int j = i; j < i + k; j++){  
                if (temp.find(s2[j]) == temp.end()){
                    break;
                }
                temp[s2[j]]--;
                if (temp[s2[j]] == 0){
                    temp.erase(s2[j]);
                }
            }
            if (temp.empty()){ 
                return true;
            }
        }
        return false;
    }
};