class Solution {
public:
    static bool comp(string a, string b) {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (int num : nums) {
            arr.push_back(to_string(num));
        }
        sort(arr.begin(), arr.end(), comp);
        string result = "";
        for (string s : arr) {
            result += s;
        }
        if (result[0]=='0'){
            return "0";
        }
        return result;
    }
};