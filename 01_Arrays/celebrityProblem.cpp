// Celebrity Problem - Two Pointer / Elimination Approach
// Given an n x n matrix M where M[a][b] == 1 means "a knows b",
// a celebrity is a person who is known by everyone else, but knows no one.

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Returns the index of the celebrity (0-based), or -1 if none exists.
    int celebrity(vector<vector<int>> &M) {
        int n = static_cast<int>(M.size());
        if (n == 0) return -1;

        int i = 0;
        int j = n - 1;

        // Step 1: Find a potential candidate by eliminating non-celebrities.
        while (i < j) {
            if (M[i][j] == 1) {
                // i knows j => i cannot be celebrity
                ++i;
            } else {
                // i does not know j => j cannot be celebrity
                --j;
            }
        }

        int cand = i;

        // Step 2: Verify candidate.
        for (int k = 0; k < n; ++k) {
            if (k == cand) continue;
            // Celebrity should not know anyone, and everyone should know celebrity.
            if (M[cand][k] == 1 || M[k][cand] == 0) {
                return -1;
            }
        }

        return cand;
    }
};

