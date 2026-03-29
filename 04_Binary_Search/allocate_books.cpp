#include <bits/stdc++.h>
using namespace std;

bool canAllocateBooks(vector<int> &arr, int k, int pages){
    int students = 1, booksAllotted = 0;
    for(int i: arr){
        booksAllotted += i;
        if(booksAllotted > pages){
            students++;
            booksAllotted = i;
        }
    }
    // cout << students << " " << k << " " << pages << endl;
    return students <= k;
}

int findPages(int *arr, int k)
{
    int n = arr.size();
        if(k > n) return -1;
        int lo = 0, hi = 0;
        for(int i: arr){
            hi  += i;
            lo = max(lo, i);
        }
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(canAllocateBooks(arr, k, mid)){
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        return lo;
}

int main()
{
    int books[] = {10, 20, 30, 40};
    int studs = 2;
    cout << findPages(books, studs) << endl;
}