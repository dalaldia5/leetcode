class TimeMap {
public:
    map<string, vector<pair<string, int>>> mpp;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mpp[key].push_back({value, timestamp});
    }

    string get(string key, int timestamp) {
        if (mpp.find(key)==mpp.end())
            return "";
        auto &vec=mpp[key];
        int l=0, h=vec.size()-1;
        string ans="";
        while (l<=h) {
            int m=l+(h-l)/2;
            if (vec[m].second>timestamp) {
                h=m-1;
            } else {
                ans=vec[m].first;
                l=m+1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */