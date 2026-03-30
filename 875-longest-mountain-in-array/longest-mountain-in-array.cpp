class Solution {
public:
    int longestMountain(vector<int>& arr) {
        if (arr.size() < 3)
            return 0;
        int maxLen=0;
        for (int i=1; i<arr.size()-1; i++){
            int j = i-1;
            int k=i+1;
            if (arr[j]>=arr[i] || arr[k]>=arr[i]){
                continue;
            }
            else {
                while(j>0 && arr[j-1]<arr[j]){
                    j--;
                }
                while (k<arr.size()-1 && arr[k+1]<arr[k]){
                    k++;
                }
                maxLen=max(maxLen, k-j+1);
            }
        }
        return maxLen;
    }
};