#include <bits/stdc++.h>
using namespace std;

void binarySearch(vector<int> arr, int size, int key){
	int s = 0;
	int e = size-1;
	while(e-s>1){ // difference between high and low should be greater than 1
		int mid = (s+e)/2;
		if(arr[mid] < key){
			s = mid+1;
		}
		else {
			e = mid;
		}
	}
	if(arr[s] == key) cout << key << " found at position: " << s << endl;
	else if (arr[e] == key) cout << key << " found at position: " << key << " found at position: "<< e << endl;
	else cout << "Not Found !";
}
int main(){
	// Binary search is applied on monotonic functions
	// monotonic functions are the ones which maintains an order
	// Like if we have an array - 1,2,3,4 this follow an order which is
	// increasing
	// or an array - 5,4,3,2,1 has a strictly decreasing order
	// Binary search is also applied on predicate functions
	// like FFFTTT - function returning F and then Trues
	// or TTTFFF - first returns Trues and then false

	vector<int> v = {1,2,3,14,15,23,27,58,69};
	int key; cin >> key;
	int n = v.size();

	binarySearch(v,n, key);

	//Binary search function in STL
	bool present = binary_search(v.begin(), v.end(), key);
	cout << present << endl;




	return 0;
}

// After every iteration search space is getting halved
// A number N can be halved log2(N) times until it becomes 0.
// Hence time complexity of Binary search is - O(log2(N))


// Another way

// #include <bits/stdc++.h>
// using namespace std;

// void b_search(vector<int> &nums, int key)
// {
// 	int s = 0;
// 	int e = size(nums);
// 	int mid;
// 	while (s < e)
// 	{
// 		mid = (s + e) / 2;
// 		if (nums[mid] == key)
// 			break;
// 		else if (nums[mid] > key)
// 		{
// 			e = mid;
// 		}
// 		else
// 		{
// 			s = mid + 1;
// 		}
// 	}
// 	cout << ((nums[mid] == key) ? mid : -1) << endl;
// }

// int main()
// {
// 	vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 67, 78};
// 	int n = size(nums);
// 	b_search(nums, 78);

// 	return 0;
// }