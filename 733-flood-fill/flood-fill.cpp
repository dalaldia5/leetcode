class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start=image[sr][sc];
        if (start==color){
            return image;
        }
        image[sr][sc]=color;
        int row=image.size();
        int col=image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int drow[4]={-1, 0, 1, 0};
        int dcol[4]={0,1,0,-1};
        while (!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for (int i=0; i<4; i++){
                int nrow=r+drow[i];
                int ncol=c+dcol[i];
                if (nrow<row && ncol<col && nrow>=0 && ncol>=0 && image[nrow][ncol]==start){
                    q.push({nrow, ncol});
                    image[nrow][ncol]=color;
                }
            }
        }
        return image;
    }
};