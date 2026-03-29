class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> start;
        vector<int> ans(n, 0);
        int prevTime=0;
        for (int i=0; i<logs.size(); i++){
            string s=logs[i];
            int p1=s.find(":");
            int p2=s.find(":", p1+1);
            int id=stoi(s.substr(0,p1));
            string type=s.substr(p1+1, p2-p1-1);
            int time=stoi(s.substr(p2+1));

            if (type=="start"){
                if (!start.empty()){
                    ans[start.top().first]+=(time-prevTime);
                }
                start.push({id, time});
                prevTime=time;
            }
            else {
                ans[start.top().first]+=(time-prevTime+1);
                start.pop();
                prevTime=time+1;
            }
        }
        return ans;
    }
};