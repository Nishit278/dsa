// LeetCode 981 — Time Based Key-Value Store (binary search on timestamps)
#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
    unordered_map<string, vector<pair<int, string>>> mp;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        if (mp.find(key) == mp.end())
            return "";

        auto &searchSpace = mp[key]; // reference, no copy
        int lo = 0, hi = (int)searchSpace.size() - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (searchSpace[mid].first > timestamp)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return hi >= 0 ? searchSpace[hi].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main()
{
    TimeMap tm;
    tm.set("foo", "bar", 1);
    tm.set("foo", "bar2", 2);
    cout << tm.get("foo", 1) << "\n"; // bar
    cout << tm.get("foo", 3) << "\n"; // bar2 (latest at or before 3)
    cout << tm.get("missing", 1) << "\n"; // empty
    return 0;
}
