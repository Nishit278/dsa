#include <bits/stdc++.h>
using namespace std;

class Heap
{
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b)
    {
        if (minHeap)
            return a < b;
        else
            return a > b;
    }

    void heapify(int root)
    {
        int left = 2 * root;
        int right = left + 1;

        int min_idx = root;
        int last = size(v) - 1;
        if (left <= last and compare(v[left], v[root]))
        {
            min_idx = left;
        }
        if (right <= last and compare(v[right], v[root]))
        {
            min_idx = right;
        }
        if (min_idx != root)
        {
            swap(v[root], v[min_idx]);
            heapify(min_idx);
        }
    }

public:
    Heap(int default_size = 10, bool type = true)
    {
        v.reserve(default_size); // vector won't expand until specified elements are not entered in the heap
        v.push_back(-1);         // -1 in the 0th index
        minHeap = type;
    }

    void push(int val)
    {
        v.push_back(val);
        int idx = size(v) - 1;
        int parent = idx / 2;
        // keep pushing up until you reach node or an element which is lesser than your current element
        while (idx > 1 and compare(v[idx], v[parent]))
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }

    int top()
    {
        return v[1];
    }

    void pop()
    {
        int last = v.size() - 1;
        swap(v[1], v[last]);
        v.pop_back();
        heapify(1);
    }
    bool empty()
    {
        return v.size() == 1;
    }
};

int main()
{
    Heap h;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        h.push(no);
    }
    while (!h.empty())
    {
        cout << h.top() << " ";
        h.pop();
    }

    return 0;
}