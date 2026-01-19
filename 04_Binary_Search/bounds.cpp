#include <bits/stdc++.h>
using namespace std;

// lower bound returns the next immediate number which is >= to the element whose lower_bound we want
int l_bound(vector<int> &v, int element)
{
	int lo = 0, hi = v.size() - 1;
	int mid;
	while (hi - lo > 1)
	{
		mid = (hi + lo) / 2;
		if (v[mid] < element)
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid;
		}
	}
	if (v[lo] >= element)
	{
		return lo;
	}
	if (v[hi] >= element)
	{
		return hi;
	}
	return -1;
}
// upper bound is the next immediate element which is strictly greater than the element whose upper bound we want.
int u_bound(vector<int> &v, int element)
{
	int lo = 0, hi = v.size() - 1;
	int mid;
	while (hi - lo > 1)
	{
		mid = (hi + lo) / 2;
		cout << v[mid] << endl;
		if (v[mid] <= element)
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid;
		}
	}
	// cout << "low: " << lo << " high: " << hi << endl;
	if (v[lo] > element)
	{
		return lo;
	}
	if (v[hi] > element)
	{
		return hi;
	}
	return -1;
}
int main()
{

	// int n; cin >> n;
	// vector < int > v(n);
	// for (int i=0;i<n;i++){
	// 	cin >> v[i];
	// }
	// int element; cin >> element;

	// int lb = l_bound(v, element);
	// int ub = u_bound(v, element);
	// cout << "Lower bound of "<< element <<  " is: " << (lb == -1 ? -1 : v[lb]) << " at: " << lb << endl;
	// cout << "Upper bound of "<< element <<  " is: " << (ub == -1 ? -1 : v[ub]) << " at: " << ub <<endl;

	// Lower and Upper bounds STL
	// lower_bound() return the first element >= key
	// upper_bound() return the first element > key (strictly greater)
	vector<int> v = {1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 6, 7, 23, 56};
	//both these functions return an iterator.
	auto lb = lower_bound(v.begin(), v.end(), 4);
	auto ub = upper_bound(v.begin(), v.end(), 4);

	cout << *lb << endl; // lower bound
	cout << *ub << endl; // upper bound
	cout << ub - lb << endl; // frequency of 4 in array

	return 0;
}

// we already have a function lower_bound() and upper_bound() in stl to calculate the lower bound and upper bound of an element in an array
// this function in STL uses the binary search approach to calculate the lower and upper bound
