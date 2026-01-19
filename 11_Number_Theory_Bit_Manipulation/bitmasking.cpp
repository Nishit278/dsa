#include <bits/stdc++.h>
using namespace std;

// Consider this problem: There are N≤5000 workers. 
// Each worker is available during some days of this month 
// (which has 30 days). For each worker, you are given a set 
// of numbers, each from interval [1,30], representing his/her 
// availability. You need to assign an important project to two 
// workers but they will be able to work on the project only when 
// they are both available. Find two workers that are best for 
// the job — maximize the number of days when both these 
// workers are available.


int main(){
	int n;
	cin >> n;
	vector<int> masks(n,0);
	for(int i=0;i<n;i++){
		int no_of_workers;
		cin >> no_of_workers;
		int mask = 0;
		for(int j=0; j<no_of_workers; j++){
			int day;
			cin >> day;
			mask = (mask | (1<< day));
		}
		masks[i]=mask;
	}
	int max_days = 0;
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			int intersection = (masks[i] & masks[j]);
			int common_days = __builtin_popcount(intersection);
			max_days = max(max_days, common_days);
			cout << i << " " << j << " " << common_days << endl;
		}
	}

	cout << "Max common days : " << max_days << endl;
	return 0;
}

/***
 * Bit masking is representing something using a mask of bits 
 * Eg: apple - 0, orange - 1, mango - 2, kiwi - 3
 * now we wanna distribute them between few people s.t.
 * 1- 0,2,3 (has apples, mangos and kiwis)
 * 2- 0,1,2
 * 3- 1,2,3 
 * to represent 1's holdings using bits 
 * we need a 4 bit number (total no of fruits) and make the bits
 * corresponding to fruit code as set bits 
 * for 1 - bit mask would be 1101
 * for 2 - 		""	""       0111
 * for 2 - 		""	""       1110
***/

// performs the intersection operation in O(1)
// size is the limitation 
// this trick works if max no of elements in an array is 64 we can use unsigned long long 
// if size > 64 we would have to use sets 

// Input
// 3
// 4
// 1 4 7 9
// 6
// 2 9 1 7 25 29 
// 7
// 1 2 3 4 7 9 11