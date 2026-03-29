/*
We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. 
Now in every subsequent row, we look at the previous row and replace each 
occurrence of 0 with 01, and each occurrence of 1 with 10.

For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd 
row is 0110.

Given two integer n and k, return the kth (1-indexed) symbol in the nth row 
of a table of n rows.
*/

/***
 * eg:
 *	1->0 size = 1 2^0
 * 	2-> 01 size = 2
 *  3-> 0110 size = 4
 *  4-> 01101001 size = 8 2^3
 * for n = i all the elements before mid = the elements of n=i-1
 * and all the elements after mid are opposite of previous one
 ***/


#include <bits/stdc++.h>
using namespace std;

bool solve(int n, int k){
	if(n==1 and k==1) return 0;
	int size = (1<<n-1);
	int mid = (size/2);
	if(k<=mid) return solve(n-1,k);
	else return !solve(n-1, k-mid);
}

int main(){
	int n, k; cin >> n >> k;
	cout << solve(n,k);
	return 0;
}