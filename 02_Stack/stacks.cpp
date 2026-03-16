#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    // 1. Next Larger Element (NGE - Next Greater Element on Right)
    vector<ll> nextLargerElement(const vector<ll> &arr) {
        int n = static_cast<int>(arr.size());
        vector<ll> result(n, -1);
        stack<ll> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = st.top();
            }
            st.push(arr[i]);
        }
        return result;
    }

    // 2. NGL - Next Greater to Left
    vector<ll> nextGreaterLeft(const vector<ll> &arr) {
        int n = static_cast<int>(arr.size());
        vector<ll> result(n, -1);
        stack<ll> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = st.top();
            }
            st.push(arr[i]);
        }
        return result;
    }

    // 3. NSL - Next Smaller to Left
    vector<ll> nextSmallerLeft(const vector<ll> &arr) {
        int n = static_cast<int>(arr.size());
        vector<ll> result(n, -1);
        stack<ll> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = st.top();
            }
            st.push(arr[i]);
        }
        return result;
    }

    // 4. NSR - Next Smaller to Right
    vector<ll> nextSmallerRight(const vector<ll> &arr) {
        int n = static_cast<int>(arr.size());
        vector<ll> result(n, -1);
        stack<ll> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = st.top();
            }
            st.push(arr[i]);
        }
        return result;
    }

    // 5. Max Histogram (Largest Rectangle in Histogram)
    long long largestRectangleArea(const vector<int> &heights) {
        int n = static_cast<int>(heights.size());
        stack<int> st;
        long long maxArea = 0;

        for (int i = 0; i <= n; ++i) {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, 1LL * height * width);
            }
            st.push(i);
        }
        return maxArea;
    }

    // 6. Stock Span - returns span for each day
    vector<int> calculateSpan(const vector<int> &arr) {
        int n = static_cast<int>(arr.size());
        vector<int> result;
        result.reserve(n);
        stack<pair<int, int>> st;  // value, span
        for (int i = 0; i < n; ++i) {
            int span = 1;
            while (!st.empty() && st.top().first <= arr[i]) {
                span += st.top().second;
                st.pop();
            }
            st.push({arr[i], span});
            result.push_back(span);
        }
        return result;
    }

    // 7. Daily Temperatures - days until warmer
    vector<int> dailyTemperatures(const vector<int> &arr) {
        int n = static_cast<int>(arr.size());
        vector<int> result(n, 0);
        stack<pair<int, int>> st;  // temp, index

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top().first <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = st.top().second - i;
            }
            st.push({arr[i], i});
        }
        return result;
    }

    // 8. Car Fleet - number of fleets reaching the target
    int carFleet(int target, const vector<int> &pos, const vector<int> &speed) {
        int n = static_cast<int>(pos.size());
        map<int, double> mp;  // -position -> time to reach target
        for (int i = 0; i < n; ++i) {
            mp[-pos[i]] = static_cast<double>(target - pos[i]) / speed[i];
        }

        int fleets = 0;
        double curr = 0.0;
        for (auto &it : mp) {
            if (it.second > curr) {
                ++fleets;
                curr = it.second;  // leading car's time for this fleet
            }
        }
        return fleets;
    }

    // 9. Maximal Rectangle of 1s in a binary matrix
    int maximalRectangle(const vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int n = static_cast<int>(matrix.size());
        int m = static_cast<int>(matrix[0].size());
        vector<int> heights(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            int area = static_cast<int>(largestRectangleArea(heights));
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    cout << "1. Next Larger Element (NGE)\n";
    cout << "2. NGL (Next Greater to Left)\n";
    cout << "3. NSL (Next Smaller to Left)\n";
    cout << "4. NSR (Next Smaller to Right)\n";
    cout << "5. Max Histogram\n";
    cout << "6. Stock Span\n";
    cout << "7. Daily Temperatures\n";
    cout << "8. Car Fleet\n";
    cout << "9. Maximal Rectangle (binary matrix)\n";
    cout << "Enter choice (1-9): ";

    int choice;
    if (!(cin >> choice)) return 0;

    switch (choice) {
        case 1: {
            int t;
            cin >> t;
            while (t--) {
                int n;
                cin >> n;
                vector<ll> arr(n);
                for (int i = 0; i < n; ++i) cin >> arr[i];
                auto res = sol.nextLargerElement(arr);
                for (ll x : res) cout << x << ' ';
                cout << '\n';
            }
            break;
        }
        case 2: {
            int t;
            cin >> t;
            while (t--) {
                int n;
                cin >> n;
                vector<ll> arr(n);
                for (int i = 0; i < n; ++i) cin >> arr[i];
                auto res = sol.nextGreaterLeft(arr);
                for (ll x : res) cout << x << ' ';
                cout << '\n';
            }
            break;
        }
        case 3: {
            int t;
            cin >> t;
            while (t--) {
                int n;
                cin >> n;
                vector<ll> arr(n);
                for (int i = 0; i < n; ++i) cin >> arr[i];
                auto res = sol.nextSmallerLeft(arr);
                for (ll x : res) cout << x << ' ';
                cout << '\n';
            }
            break;
        }
        case 4: {
            int t;
            cin >> t;
            while (t--) {
                int n;
                cin >> n;
                vector<ll> arr(n);
                for (int i = 0; i < n; ++i) cin >> arr[i];
                auto res = sol.nextSmallerRight(arr);
                for (ll x : res) cout << x << ' ';
                cout << '\n';
            }
            break;
        }
        case 5: {
            int n;
            cin >> n;
            vector<int> h(n);
            for (int i = 0; i < n; ++i) cin >> h[i];
            cout << sol.largestRectangleArea(h) << '\n';
            break;
        }
        case 6: {
            int n;
            cin >> n;
            vector<int> a(n);
            for (int i = 0; i < n; ++i) cin >> a[i];
            auto res = sol.calculateSpan(a);
            for (int x : res) cout << x << ' ';
            cout << '\n';
            break;
        }
        case 7: {
            int n;
            cin >> n;
            vector<int> temps(n);
            for (int i = 0; i < n; ++i) cin >> temps[i];
            auto res = sol.dailyTemperatures(temps);
            for (int x : res) cout << x << ' ';
            cout << '\n';
            break;
        }
        case 8: {
            int target, n;
            cin >> target >> n;
            vector<int> pos(n), speed(n);
            for (int i = 0; i < n; ++i) cin >> pos[i];
            for (int i = 0; i < n; ++i) cin >> speed[i];
            cout << sol.carFleet(target, pos, speed) << '\n';
            break;
        }
        case 9: {
            int n, m;
            cin >> n >> m;
            vector<vector<char>> matrix(n, vector<char>(m));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cin >> matrix[i][j];
                }
            }
            cout << sol.maximalRectangle(matrix) << '\n';
            break;
        }
        default:
            cout << "Invalid choice\n";
    }

    return 0;
}
