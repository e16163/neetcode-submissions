class TimeMap {
public:
    map<string, vector<pair<int, string>>> timeMap;
    
    TimeMap() {
        map<string, vector<pair<int, string>>> timeMap;
    }
    
    void set(string key, string value, int timestamp) {
        pair<int, string> p = {timestamp, value};
        timeMap[key].push_back(p);

    }
    
    string get(string key, int timestamp) {
        int maxprev = -1;
        string ans;
        vector<pair<int, string>> times = timeMap[key];
        int left = 0;
        int right = times.size()-1;
        int mid = (right - left + 1)/2;
        int length = right - left + 1;
        while (length > 0)
        {
            mid = (right + left + 1)/2;
            
            if (timestamp < times[mid].first)
            {
                if (times[mid].first > maxprev && times[mid].first <= timestamp)
                {
                    ans = times[mid].second;
                    maxprev = times[mid].first;
                }
                right = mid - 1;

            }
            else if (timestamp > times[mid].first)
            {
                if (times[mid].first > maxprev && times[mid].first <= timestamp)
                {
                    ans = times[mid].second;
                    maxprev = times[mid].first;
                }
                left = mid + 1;

            }
            else if (timestamp == times[mid].first)
            {
                return times[mid].second;
            }
            length = right - left + 1;
            
        }
        return ans;
        


    }
};
