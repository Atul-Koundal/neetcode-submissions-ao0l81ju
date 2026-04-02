class TimeMap {
public:unordered_map<string,<pair<int,string>> mp;
unordered_map < string,vector<pair<int, string>>> mp;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end())
            return "";

        const vector<pair<int, string>>& entries = mp[key];

        int l = 0;
        int r = entries.size() - 1;
        string result = "";
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int midTimestamp = entries[mid].first;
            if (midTimestamp == timestamp) {
                // Exact timestamp match
                return entries[mid].second;
            } else if (midTimestamp < timestamp) {
                // Possible candidate, but maybe there's a later one
                result = entries[mid].second;
                l = mid + 1;
            } else {
                // Too late, move left
                r = mid - 1;
            }
        }

        return result;
    }
};