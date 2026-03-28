#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Binary search is applied on monotonic functions
    // monotonic functions are the ones which maintains an order
    // Like if we have an array - 1,2,3,4 this follow an order which is
    // increasing
    // or an array - 5,4,3,2,1 has a strictly decreasing order
    // Binary search is also applied on predicate functions
    // like FFFTTT - function returning F and then Trues
    // or TTTFFF - first returns Trues and then false
    // After every iteration search space is getting halved
    // A number N can be halved log2(N) times until it becomes 0.
    // Hence time complexity of Binary search is - O(log2(N))

    // 1. Basic binary search: return index of key in sorted array, or -1 if not found.
    int binarySearch(const vector<int> &nums, int key) {
        int s = 0;
        int e = nums.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == key) return mid;
            if (nums[mid] < key) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1;
    }

    // 2. First occurrence of key in sorted array.
    int firstOccurrence(const vector<int> &nums, int key) {
        int s = 0;
        int e = nums.size();
        int ans = -1;
        while (s < e) {
            int mid = (s + e) / 2;
            if (nums[mid] == key) {
                ans = mid;
                e = mid;  // move left
            } else if (nums[mid] > key) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }

    // 3. Last occurrence of key in sorted array.
    int lastOccurrence(const vector<int> &nums, int key) {
        int s = 0;
        int e = nums.size();
        int ans = -1;
        while (s < e) {
            int mid = (s + e) / 2;
            if (nums[mid] == key) {
                ans = mid;
                s = mid + 1;  // move right
            } else if (nums[mid] > key) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }

    // lower bound returns the next immediate number which is >= to the element whose lower_bound we want
    // 4. Manual lower_bound: first index with value >= element, or -1 if none.
    int lowerBound(const vector<int> &v, int element) {
        int lo = 0, hi = v.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (v[mid] < element)
                lo = mid + 1;
            else
                hi = mid;
        }
    
        return lo;
    }

    // upper bound is the next immediate element which is strictly greater than the element whose upper bound we want.
    // 5. Manual upper_bound: first index with value > element, or -1 if none.
    int upperBound(const vector<int> &v, int element) {
        int lo = 0, hi = v.size();
    
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (v[mid] <= element)
                lo = mid + 1;
            else
                hi = mid;
        }
    
        return lo;
    }

    // 6. Peak element (any peak index), array not necessarily sorted.
    int peakElement(const vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return -1;
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            bool leftOK = (mid == 0 || nums[mid] > nums[mid - 1]);
            bool rightOK = (mid == n - 1 || nums[mid] > nums[mid + 1]);
            if (leftOK && rightOK) return mid;
            if (mid < n - 1 && nums[mid] <= nums[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    // since no array is given think of a search space (Monotonic)
    // Monotonic function means a function which is non increasing or non decreasing
    // min square root of a number can be 1 and could be the number itself
    // 1-50, take mid 25, 25^2 > 50, so 25 and all nums after that can't be square root
    // this is the monotonic property
    // 7. Integer sqrt with decimal precision p (like square_root.cpp).
    // Returns a double approximation.
    double sqrtWithPrecision(int n, int p) {
        int s = 1, e = n;
        double ans = -1;
        while (s <= e) {
            int mid = (s + e) >> 1;
            long long sq = 1LL * mid * mid;
            if (sq == n) {
                ans = mid;
                break;
            } else if (sq > n) {
                e = mid - 1;
            } else {
                s = mid + 1;
                ans = mid;
            }
        }
        double inc = 0.1;
        for (int times = 1; times <= p; times++) {
            while (ans * ans <= n) {
                ans += inc;
            }
            ans -= inc;
            inc /= 10.0;
        }
        return ans;
    }

    double eps_global = 1e-9;
    // this is the code for square root
    // 8. nth root of x using binary search on doubles (like nth_root.cpp).
    double nthRoot(double x, int n) {
        auto multiply = [n](double mid) {
            double ans = 1.0;
            for (int i = 0; i < n; ++i) ans *= mid;
            return ans;
        };
        double lo = 1.0, hi = x, mid;
        while (hi - lo > eps_global) {
            mid = (hi + lo) / 2.0;
            if (multiply(mid) < x) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return lo;  // or hi; both are within eps
    }

    // 9. Aggressive cows (AGGRCOW) - maximum minimum separation.
    int aggressiveCows(vector<int> stalls, int cows) {
        int n = stalls.size();
        if (n == 0 || cows <= 0) return 0;
        sort(stalls.begin(), stalls.end());

        auto canPlace = [&](int min_sep) {
            int last_cow = stalls[0];
            int cnt = 1;
            for (int i = 1; i < n; ++i) {
                if (stalls[i] - last_cow >= min_sep) {
                    last_cow = stalls[i];
                    ++cnt;
                    if (cnt == cows) return true;
                }
            }
            return false;
        };

        int s = 0, e = stalls[n - 1] - stalls[0];
        int ans = 0;
        while (s <= e) {
            int mid = (s + e) / 2;
            if (canPlace(mid)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }

    // 10. Allocate minimum number of pages (allocate_books.cpp).
    // nums: pages in each book, c: number of students.
    int allocateBooks(const vector<int> &nums, int c) {
        int n = nums.size();
        if (c > n || n == 0) return -1;

        auto isValid = [&](int maxPages) {
            int student = 1;
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += nums[i];
                if (sum > maxPages) {
                    ++student;
                    sum = nums[i];
                }
            }
            return student <= c;
        };

        int s = 0, e = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            e += nums[i];
            s = max(s, nums[i]);
        }
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isValid(mid)) {
                res = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif3

    Solution sol;

    cout << "1. Basic Binary Search\n";
    cout << "2. First & Last Occurrence\n";
    cout << "3. Lower & Upper Bound\n";
    cout << "4. Peak Element\n";
    cout << "5. Sqrt With Precision\n";
    cout << "6. Nth Root\n";
    cout << "7. Aggressive Cows\n";
    cout << "8. Allocate Books\n";
    cout << "Enter choice (1-8): ";

    int choice;
    if (!(cin >> choice)) return 0;

    switch (choice) {
        case 1: {
            int n, key;
            cin >> n >> key;
            vector<int> a(n);
            for (int i = 0; i < n; ++i) cin >> a[i];
            cout << sol.binarySearch(a, key) << "\n";
            break;
        }
        case 2: {
            int n, key;
            cin >> n >> key;
            vector<int> a(n);
            for (int i = 0; i < n; ++i) cin >> a[i];
            int f = sol.firstOccurrence(a, key);
            int l = sol.lastOccurrence(a, key);
            cout << f << " " << l << "\n";
            break;
        }
        case 3: {
            int n, x;
            cin >> n >> x;
            vector<int> a(n);
            for (int i = 0; i < n; ++i) cin >> a[i];
            int lb = sol.lowerBound(a, x);
            int ub = sol.upperBound(a, x);
            cout << lb << " " << ub << "\n";
            break;
        }
        case 4: {
            int n;
            cin >> n;
            vector<int> a(n);
            for (int i = 0; i < n; ++i) cin >> a[i];
            cout << sol.peakElement(a) << "\n";
            break;
        }
        case 5: {
            int n, p;
            cin >> n >> p;
            cout << sol.sqrtWithPrecision(n, p) << "\n";
            break;
        }
        case 6: {
            double x;
            int n;
            cin >> x >> n;
            cout << sol.nthRoot(x, n) << "\n";
            break;
        }
        case 7: {
            int n, cows;
            cin >> n >> cows;
            vector<int> stalls(n);
            for (int i = 0; i < n; ++i) cin >> stalls[i];
            cout << sol.aggressiveCows(stalls, cows) << "\n";
            break;
        }
        case 8: {
            int n, students;
            cin >> n >> students;
            vector<int> pages(n);
            for (int i = 0; i < n; ++i) cin >> pages[i];
            cout << sol.allocateBooks(pages, students) << "\n";
            break;
        }
        default:
            cout << "Invalid choice\n";
    }

    return 0;
}

